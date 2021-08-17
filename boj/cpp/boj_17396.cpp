#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const ll INF = ((ll)1 << 62);
struct comp {
	bool operator()(pli p1, pli p2) {
		return p1.first > p2.first;
	}
};
int N, M, a, b;
ll t,dist[100000];
bool iswarding[100000];
vector<pli> adjlist[100000];
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		iswarding[i] = ((a==0)?false:true);
		dist[i] = INF;
	}
	iswarding[N - 1] = false;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%lld", &a, &b, &t);
		if (!iswarding[a] && !iswarding[b]) {
			adjlist[a].push_back(pli(t, b));
			adjlist[b].push_back(pli(t, a));
		}
	}
	priority_queue<pli,vector<pli>,comp> pq;
	dist[0] = 0;
	pq.push(pli(0, 0));
	while (!pq.empty()) {
		pli t = pq.top();
		pq.pop();
		
		if (t.first > dist[t.second]) continue;
		for (int i = 0; i < adjlist[t.second].size(); i++) {
			pli Edge = adjlist[t.second][i];
			ll ndist = t.first + Edge.first;
			if (ndist < dist[Edge.second]) {
				dist[Edge.second] =ndist;
				pq.push(pli(ndist, Edge.second));			
			}
		}
	}
	if (dist[N - 1] == INF) {
		printf("-1\n");
	}
	else {
		printf("%lld\n", dist[N - 1]);
	}
	return 0;
}