#include<iostream>
#include<string>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, M, P, dps[26],dp,HP,arrivetime[26],visit[1000][1000];
string map[1000];
char c;
pii d[4] = { pii(1,0),pii(0,1),pii(-1,0),pii(0,-1) };
queue<pii> q;
int main() {
	ios::sync_with_stdio(false);
	cin >> M >> N >> P;
	for (int i = 0; i < 26; i++) {
		dps[i] = -1;
		arrivetime[i] = -1;
	}
	for (int i = 0; i < M; i++) {
		cin >> map[i];
		for (int j = 0; j < N; j++) {
			visit[i][j] = -1;
		}
	}
	for (int i = 0; i < P; i++) {
		cin >> c >> dp;
		dps[c - 'a'] = dp;
	}
	for (int i = 0; i < M*N; i++) {
		if (map[i / N][i % N] == 'B') {
			q.push(pii(i / N, i % N));
			visit[i / N][i % N] = 0;
			while (!q.empty()) {
				pii t = q.front();
				q.pop();
				for (int j = 0; j < 4; j++) {
					int nr = t.first + d[j].first;
					int nc = t.second + d[j].second;
					if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
					if (visit[nr][nc] == -1 && map[nr][nc] != 'X') {
						visit[nr][nc] = visit[t.first][t.second] + 1;
						if (map[nr][nc] >= 'a' && map[nr][nc] <= 'z') {
							arrivetime[map[nr][nc] - 'a'] = visit[nr][nc];
						}
						q.push(pii(nr, nc));
						
					}

				}

			}
			break;
		}
	}
	cin >> HP;
	int ntime = 0;
	int answer = 0;
	int ndps = 0;
	while (HP > 0 && answer < P) {
		for (int i = 0; i < 26; i++) {
			if (ntime == arrivetime[i]) {
				ndps += dps[i];
				answer++;
			}
		}
		HP -= ndps;
		ntime++;
	}
	cout << answer << "\n";
	return 0;
}