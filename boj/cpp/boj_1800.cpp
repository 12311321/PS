#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
const int INF = 10001;
int N, P, K, dp[1001][1000], a, b, c, pn[1000];
bool visit[1000];
vector<pii> adjlist[1000];
struct compare {
	bool operator()(pii p1, pii p2) {
		return p1.second > p2.second;
	}
};
priority_queue<pii, vector<pii>, compare> pq;
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> P >> K;
	int mincost = 0, maxcost = 0;;
	for (int i = 0; i < P; i++) {
		cin >> a >> b >> c;
		maxcost = max(c, maxcost);
		adjlist[a - 1].push_back(pii(b - 1, c));
		adjlist[b - 1].push_back(pii(a - 1, c));
	}
	bool f = false;
	while (mincost!=maxcost) {
		for (int i = 0; i < N; i++) {
			pn[i] = INF;
			visit[i] = false;
		}
		int midcost = (mincost + maxcost) / 2;
		pq.push(pii(0, 0));
		pn[0] = 0;

		while (!pq.empty()) {
			pii t = pq.top();

			pq.pop();
			if (!visit[t.first]) {
				visit[t.first] = true;
				for (int i = 0; i < adjlist[t.first].size(); i++) {
					pii edge = adjlist[t.first][i];
					int ncost = pn[t.first] + (edge.second > midcost);
					if (ncost < pn[edge.first]) {
						pn[edge.first] = ncost;
						pq.push(pii(edge.first, pn[edge.first]));
					}
				}
			}
		}
		if (pn[N - 1] ==INF) {
			mincost = -1;
			break;
		}
		if (pn[N - 1] <= K) {
		
			maxcost = midcost;
		}
		else {
			mincost = midcost + 1;
		}
		
	}
	
	cout << mincost << "\n";
	return 0;
}