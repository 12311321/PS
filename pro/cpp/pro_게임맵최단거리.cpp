#include<vector>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
int check[100][100];
pii d[4] = { pii(1,0),pii(-1,0),pii(0,1),pii(0,-1) };
queue<pii> q;
int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            check[i][j] = -1;
        }
    }
    check[0][0] = 1;
    q.push(pii(0, 0));
    while (!q.empty()) {
        pii t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = t.first + d[i].first;
            int nc = t.second + d[i].second;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && maps[nr][nc] == 1 && check[nr][nc] == -1) {
                check[nr][nc] = check[t.first][t.second] + 1;
                q.push(pii(nr, nc));
            }
        }
    }
    return check[n - 1][m - 1];
}