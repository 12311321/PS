#include <vector>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
bool visit[100][100];
pii d[4] = { pii(1,0),pii(-1,0),pii(0,1),pii(0,-1) };
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visit[i][j] = false;
        }
    }
    queue<pii> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j] && picture[i][j] > 0) {
                int sz = 0;
                int color = picture[i][j];
                visit[i][j] = true;
                q.push(pii(i, j));
                while (!q.empty()) {
                    pii t = q.front();
                    q.pop();
                    sz++;
                    for (int k = 0; k < 4; k++) {
                        int nr = t.first + d[k].first;
                        int nc = t.second + d[k].second;
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                        if (visit[nr][nc] || picture[nr][nc] != color) continue;
                        visit[nr][nc] = true;
                        q.push(pii(nr, nc));
                    }
                }
                number_of_area++;
                max_size_of_one_area = max_size_of_one_area < sz ? sz : max_size_of_one_area;
            }
        }
    }


    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}