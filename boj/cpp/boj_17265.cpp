#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N,dp[2][5][5];
char map[5][5];
bool visit[5][5];
queue<pii> q;
pii d[2] = { pii(1,0),pii(0,1) };
int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			visit[i][j] = false;
		}
	}
	dp[0][0][0] = map[0][0] - '0';
	dp[1][0][0] = map[0][0] - '0';
	visit[0][0] = true;
	q.push(pii(0, 0));
	//BFS
	while (!q.empty()) {
		pii t = q.front();
		
		q.pop();
		for (int i = 0; i < 2; i++) {
			int r = t.first + d[i].first;
			int c = t.second+d[i].second;
			if (r< N && c<N) {
				//숫자일 경우 그대로 넘겨줌
				if (map[t.first][t.second] >= '0' && map[t.first][t.second] <= '9') {
					if (!visit[r][c]) {
						dp[0][r][c] = dp[0][t.first][t.second];
						dp[1][r][c] =  dp[1][t.first][t.second];
						visit[r][c] = true;
						q.push(pii(r, c));
					}
					else {
						dp[0][r][c] = max(dp[0][r][c], dp[0][t.first][t.second]);
						dp[1][r][c] = min(dp[1][r][c], dp[1][t.first][t.second]);
					}
				}
				else { // 연산자일 경우 연산한 값을 넘겨줌
					switch (map[t.first][t.second]) {
					case'+':
						if (!visit[r][c]) {
							dp[0][r][c] = dp[0][t.first][t.second]+(map[r][c]-'0');
							dp[1][r][c] = dp[1][t.first][t.second]+(map[r][c]-'0');
							visit[r][c] = true;
							q.push(pii(r, c));
						}
						else {
							dp[0][r][c] = max(dp[0][r][c], dp[0][t.first][t.second] + (map[r][c] - '0'));
							dp[1][r][c] = min(dp[1][r][c], dp[1][t.first][t.second] + (map[r][c] - '0'));
						}
						break;
					case '-':
						if (!visit[r][c]) {
							dp[0][r][c] = dp[0][t.first][t.second] - (map[r][c] - '0');
							dp[1][r][c] = dp[1][t.first][t.second] - (map[r][c] - '0');
							visit[r][c] = true;
							q.push(pii(r, c));
						}
						else {
							dp[0][r][c] = max(dp[0][r][c], dp[0][t.first][t.second] - (map[r][c] - '0'));
							dp[1][r][c] = min(dp[1][r][c], dp[1][t.first][t.second] - (map[r][c] - '0'));
						}
						break;
					case '*':
						if (!visit[r][c]) {
							dp[0][r][c] = dp[0][t.first][t.second] * (map[r][c] - '0');
							dp[1][r][c] = dp[1][t.first][t.second] * (map[r][c] - '0');
							visit[r][c] = true;
							q.push(pii(r, c));
						}
						else {
							dp[0][r][c] = max(dp[0][r][c], dp[0][t.first][t.second] * (map[r][c] - '0'));
							dp[1][r][c] = min(dp[1][r][c], dp[1][t.first][t.second] * (map[r][c] - '0'));
						}
						break;
					}
				}
			}
		}
		
	}
	cout << dp[0][N - 1][N-1] << " " << dp[1][N - 1][N - 1] << "\n";
	return 0;
}