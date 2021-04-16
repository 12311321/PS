#include<iostream>
#include<queue>
using namespace std;
struct pos {
	int r;
	int c;
	pos(int r, int c) {
		this->r = r;
		this->c = c;
	}
};
int N, M, map[8][8],answer,zeroCount,visit[8][8],ct;
pos d[4] = { pos(1,0),pos(-1,0),pos(0,1),pos(0,-1) };
int BFS() {
	queue<pos> q;
	int ret = zeroCount - 3;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2) {
				q.push(pos(i,j));
			}
		}
	}
	while (!q.empty()) {
		pos t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = t.r + d[i].r;
			int nc = t.c + d[i].c;
			if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
				if (map[nr][nc] == 0 && visit[nr][nc] != ct) {
					visit[nr][nc] = ct;
					ret--;
					
					q.push(pos(nr, nc));
				}
			}
		}

	}
	return ret;
}
int main() {
	scanf("%d%d", &N, &M);
	zeroCount = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			zeroCount += (map[i][j] == 0);
			visit[i][j] = -1;
		}
	}
	answer = 0;
	ct = 0;
	int comb[3] = { 0,1,2 };
	while (1) {
		pos p[3] = { pos(comb[0] / M,comb[0] % M),pos(comb[1] / M,comb[1] % M), pos(comb[2] / M,comb[2] % M) };
		if (map[p[0].r][p[0].c] == 0 && map[p[1].r][p[1].c] == 0 && map[p[2].r][p[2].c] == 0) {
			map[p[0].r][p[0].c] = 1;
			map[p[1].r][p[1].c] = 1;
			map[p[2].r][p[2].c] = 1;
			int t = BFS();
			answer = answer < t ? t : answer;

			map[p[0].r][p[0].c] = 0;
			map[p[1].r][p[1].c] = 0;
			map[p[2].r][p[2].c] = 0;

		}
		int idx = 2;
		while (idx>=0 && comb[idx] == N * M + idx - 3) {
			idx--;
		}
		if (idx == -1) {
			break;
		}
		comb[idx]++;
		for (int i = idx + 1; i < 3; i++) {
			comb[i] = comb[i - 1] + 1;
		}
		ct++;
	}
	printf("%d\n", answer);
	return 0;
}
