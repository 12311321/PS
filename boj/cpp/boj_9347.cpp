/*

https://www.e-olymp.com/en/contests/3425/problems/27966

*/

#include<iostream>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int T, R, C, map[1002][1002], visit[1002][1002];
pii dir[4] = { pii(1,0),pii(0,1),pii(-1,0),pii(0,-1) };
pii BFS();
int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d%d", &R, &C);
		for (int i = 0; i <= C + 1; i++) {
			map[0][i] = 0;
			map[R + 1][i] = 0;
			visit[0][i] = -1;
			visit[R + 1][i] = -1;
		}
		for (int i = 0; i <= R + 1; i++) {
			map[i][0] = 0;
			map[i][C + 1] = 0;
			visit[i][0] = -1;
			visit[i][C + 1] = -1;
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				scanf("%d", &map[i][j]);
				visit[i][j] = -1;
			}
		}
		pii ans = BFS();
		printf("%d %d\n", ans.first, ans.second);

	}
	return 0;
}
pii BFS() {
	pii ret;
	deque<pii> dq;
	visit[0][0] = 0;
	dq.push_front(pii(0, 0));
	ret.first = 0;
	while (!dq.empty()) {
		pii t = dq.front();
		dq.pop_front();
		if (map[t.first][t.second] == 0) {
			ret.first = visit[t.first][t.second] ? visit[t.first][t.second] : ret.first;
		}
		for (int i = 0; i < 4; i++) {
			int nr = t.first + dir[i].first;
			int nc = t.second + dir[i].second;
			if (nr<0 || nr>R + 1 || nc<0 || nc>C + 1 || visit[nr][nc] != -1) continue;
			if (map[nr][nc] == 1) {
				visit[nr][nc] = visit[t.first][t.second] + 1;
				dq.push_back(pii(nr, nc));
			}
			else {
				visit[nr][nc] = visit[t.first][t.second];
				dq.push_front(pii(nr, nc));
			}
		}
	}

	ret.second = 0;
	for (int i = 1; i < R + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			if (map[i][j]==0 && visit[i][j] == ret.first) {
				ret.second++;
			}
			
		}
	}
	return ret;
}