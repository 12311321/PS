#include <string>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
int BlockDel(int m, int n, vector<string>& board);
void BlockDown(int m, int n, vector<string>& board);
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (1) {
        int r = BlockDel(m, n, board);
        if (r == 0) {
            break;
        }
        answer += r;
        BlockDown(m, n, board);
    }
    return answer;
}
int BlockDel(int m, int n, vector<string>& board) {
    int ret = 0;
    vector<pii> v;
    v.clear();
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (board[i][j] == ' ')continue;
            char c = board[i][j];
            if (c == board[i + 1][j] && c == board[i + 1][j + 1] && c == board[i][j + 1]) {
                v.push_back(pii(i + 1, j));
                v.push_back(pii(i + 1, j + 1));
                v.push_back(pii(i, j));
                v.push_back(pii(i, j + 1));
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        pii t = v[i];
        if (board[t.first][t.second] != ' ') {
            board[t.first][t.second] = ' ';
            ret++;
        }
    }
    return ret;
}
void BlockDown(int m, int n, vector<string>& board) {
    for (int c = 0; c < n; c++) {
        int pos = m - 1;
        for (int r = m - 1; r >= 0; r--) {
            if (board[r][c] != ' ') {
                char temp = board[r][c];
                board[r][c] = ' ';
                board[pos--][c] = temp;
            }
        }
    }

}