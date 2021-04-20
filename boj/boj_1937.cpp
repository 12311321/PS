#include<iostream>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int n,map[500][500],visit[500][500];
pii d[4] = { pii(1,0),pii(-1,0),pii(0,1),pii(0,-1) };
struct comp {
	bool operator()(pii p1, pii p2) {
		return map[p1.first][p1.second] > map[p2.first][p2.second]; 
	}
};
int main() {
	scanf("%d", &n);
	priority_queue<pii, vector<pii>, comp> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			visit[i][j] = 0;
			pq.push(pii(i, j));

		}
	}
	int answer = 0;
	while (!pq.empty()) {
		pii t = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int r = t.first + d[i].first;
			int c = t.second + d[i].second;
			if (r >= 0 && r < n && c >= 0 && c < n) {
				if (visit[r][c]<visit[t.first][t.second] + 1 && map[r][c]>map[t.first][t.second]) {
					visit[r][c] = visit[t.first][t.second] + 1;
					answer = answer < visit[r][c] ? visit[r][c] : answer;
				}
			}
		}
	}
	
	printf("%d\n", answer+1);
	return 0;
}