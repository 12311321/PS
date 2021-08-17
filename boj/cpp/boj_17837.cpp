#include<iostream>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
struct Info {
	pii pos;
	int d;
	int idx;
	Info() {};
	Info(pii pos, int d, int idx) {
		this->pos = pos;
		this->d = d;
		this->idx = idx;
	}
};
int N, K,map[12][12];
vector<Info*> st[12][12];
Info input[12];
pii dir[4] = { pii(0,1),pii(0,-1),pii(-1,0),pii(1,0) };

bool OneTurn() {
	for (int i = 0; i < K; i++) {
		pii p = input[i].pos;
		int nr = p.first + dir[input[i].d].first;
		int nc = p.second + dir[input[i].d].second;
		if (nr >= N || nc >= N || nr < 0 || nc < 0 || map[nr][nc] == 2) {
			if (input[i].d % 2 == 0) {
				input[i].d ++;
			}
			else {
				input[i].d --;
			}
			nr = p.first + dir[input[i].d].first;
			nc = p.second + dir[input[i].d].second;
			if (nr >= N || nc >= N || nr < 0 || nc < 0 || map[nr][nc] == 2) {
				continue;
			}
			else if (map[nr][nc] == 0) {
				int s = input[i].idx;
				int e = st[p.first][p.second].size();
				for (int j = s; j < e; j++) {
					st[nr][nc].push_back(st[p.first][p.second][j]);
					st[p.first][p.second][j]->pos = pii(nr, nc);
					st[p.first][p.second][j]->idx = st[nr][nc].size() - 1;

				}
				for (int j = s; j < e; j++) {
					st[p.first][p.second].pop_back();
				}
			}
			else {
				int s = st[p.first][p.second].size() - 1;
				int e = input[i].idx;
				for (int j = s; j >= e; j--) {
					st[nr][nc].push_back(st[p.first][p.second][j]);
					st[p.first][p.second][j]->pos = pii(nr, nc);
					st[p.first][p.second][j]->idx = st[nr][nc].size() - 1;
					st[p.first][p.second].pop_back();
				}
			}
		}
		else if (map[nr][nc] == 1) {
			int s = st[p.first][p.second].size()-1;
			int e = input[i].idx;
			for (int j = s; j >= e; j--) {
				st[nr][nc].push_back(st[p.first][p.second][j]);
				st[p.first][p.second][j]->pos = pii(nr, nc);
				st[p.first][p.second][j]->idx = st[nr][nc].size() - 1;
				st[p.first][p.second].pop_back();
			}
			
		}
		else {
			int s = input[i].idx;
			int e = st[p.first][p.second].size();
			for (int j = s; j < e; j++) {
				st[nr][nc].push_back(st[p.first][p.second][j]);
				st[p.first][p.second][j]->pos = pii(nr, nc);
				st[p.first][p.second][j]->idx = st[nr][nc].size() - 1;
			
			}
			for (int j = s; j < e; j++) {
				st[p.first][p.second].pop_back();
			}
		}
		
		if (st[input[i].pos.first][input[i].pos.second].size() >= 4) {
			return true;
		}

	}
	return false;
}
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			st[i][j].clear();
		}
	}
	for (int i = 0; i < K; i++) {
		pii pos;
		int d;
		scanf("%d%d%d", &pos.first, &pos.second, &d);
		pos.first--;
		pos.second--;
		d--;
		input[i] = Info(pos, d, 0);
		st[input[i].pos.first][input[i].pos.second].push_back(&input[i]);
	}
	int answer = -1;
	for (int i = 1; i <= 1000; i++) {	
		
		if (OneTurn()) {
			answer = i;
			break;
		}
	}
	printf("%d\n", answer);
	return 0;
}