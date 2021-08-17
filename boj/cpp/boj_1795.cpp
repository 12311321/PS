#include <iostream>
#include<string>
#include<utility>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
struct Info {
	pii pos;
	int k;
	Info(pii pos, int k) {
		this->pos = pos;
		this->k = k;
	}
};
int N, M, dist[250][50][50];
pii dir[8] = { pii(-2,1),pii(-2,-1),pii(2,1),pii(2,-1),pii(1,2),pii(1,-2),pii(-1,2),pii(-1,-2) };
string map[50];
vector<Info> v;
void Init();
void BFS(int idx);
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			if (map[i][j] >= '1' && map[i][j] <= '9') {
				v.push_back(Info(pii(i, j), map[i][j] - '0'));
			}

		}
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				dist[i][j][k] = -1;
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		BFS(i);
	}
	int ans = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int sum = 0;
			for (int k = 0; k < v.size(); k++) {
				if (dist[k][i][j] == -1) {
					sum = -1;
					break;
				}
				else {
					sum += dist[k][i][j] / v[k].k + (dist[k][i][j] % v[k].k != 0);
				}
			}
			if (sum == -1) continue;
			if (ans == -1) {
				ans = sum;
			}
			else {
				ans = ans > sum ? sum : ans;
			}
		}
	}


	cout << ans << "\n";
	return 0;
}

void BFS(int idx) {
	dist[idx][v[idx].pos.first][v[idx].pos.second] = 0;
	queue<pii> q;
	q.push(v[idx].pos);
	while (!q.empty()) {
		pii t = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nr = t.first + dir[i].first;
			int nc = t.second + dir[i].second;
			if (nr < 0 || nr >= N || nc < 0 || nc >= M || dist[idx][nr][nc] != -1) continue;
			dist[idx][nr][nc] = dist[idx][t.first][t.second] + 1;
			q.push(pii(nr, nc));
		}
	}

}