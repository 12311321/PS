#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

char Map[110][110];
int row, col;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int safe(int x, int y)
{
    if (0 <= x && x < row && 0 <= y && y < col)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool solve(int x, int y)
{
    char Find = Map[x][y];

    for (int i = 0; i < 4; i++)
    {
        int xpos = x + dx[i];
        int ypos = y + dy[i];

        while (safe(xpos, ypos) == 1 && (Map[xpos][ypos] == '.' || Map[xpos][ypos] == Find))
        {
            if (Map[xpos][ypos] == Find)
            {
                Map[x][y] = '.';
                Map[xpos][ypos] = '.';
                return true;
            }

            for (int j = 0; j < 4; j++)
            {
                if (i == j || (i == 0 && j == 1) || (i == 1 && j == 0) || (i == 2 && j == 3) || (i == 3 && j == 2))
                {
                    continue;
                }

                int nx = xpos + dx[j];
                int ny = ypos + dy[j];

                while (safe(nx, ny) == 1 && (Map[nx][ny] == '.' || Map[nx][ny] == Find))
                {
                    if (Map[nx][ny] == Find)
                    {
                        Map[x][y] = '.';
                        Map[nx][ny] = '.';
                        return true;
                    }

                    nx += dx[j];
                    ny += dy[j];
                }
            }

            xpos += dx[i];
            ypos += dy[i];
        }
    }

    return false;
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
string solution(int m, int n, vector<string> board)
{
    string answer = "";
    row = m;
    col = n;

    vector<pair<char, pair<int, int>>> reserve;
    map<char, int> alphabet_check;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Map[i][j] = board[i][j];

            if ('A' <= Map[i][j] && Map[i][j] <= 'Z' && alphabet_check[Map[i][j]] == 0)
            {
                alphabet_check[Map[i][j]] = 1;
                reserve.push_back({ Map[i][j], {i, j} });
            }
        }
    }
    sort(reserve.begin(), reserve.end());

    bool Flag = true;
    while (Flag)
    {
        Flag = false;

        for (int i = 0; i < reserve.size(); i++)
        {
            Flag = solve(reserve[i].second.first, reserve[i].second.second);

            if (Flag == true)
            {
                answer += reserve[i].first;
                reserve.erase(reserve.begin() + i);

                break;
            }
        }
    }

    if (reserve.size() != 0)
    {
        answer = "IMPOSSIBLE";
    }

    return answer;
}
int main() {
    int m = 10;
    int y = 10;

    vector<string> board;
    board.push_back("..*E..");
    board.push_back("*...A.");
    board.push_back("ACDD..");
    board.push_back("FCFG*.");
    board.push_back("Y.L.YE");
    board.push_back("...GL.");
    cout << solution(6,6,board) << endl;

    return 0;
}
