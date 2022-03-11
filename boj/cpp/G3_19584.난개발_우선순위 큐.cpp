#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
struct Edge {
	int top, bottom;
	ll cost;
};
int N, M,a,b,ypos[200020];
ll c;
Edge e[200020];
struct compBottom {
	bool operator()(const Edge& a, const Edge& b) {
		return a.bottom > b.bottom;
	}
};
bool compTop(const Edge& a, const Edge& b) {
	return a.top < b.top;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a >> ypos[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		e[i].top = min(ypos[a-1], ypos[b-1]);
		e[i].bottom = max(ypos[a-1], ypos[b-1]);
		e[i].cost = c;
	}
	sort(e, e + M, compTop);
	priority_queue<Edge, vector<Edge>, compBottom> pq;
	ll ans = 0;
	ll n = 0;
	for (int i = 0; i < M; i++) {
		
		while (!pq.empty() && pq.top().bottom < e[i].top) {
			n -= pq.top().cost;
			pq.pop();
		}
		n += e[i].cost;
		pq.push(e[i]);
		ans = max(ans, n);
	}
	cout << ans << "\n";
	return 0;
}