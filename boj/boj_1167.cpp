#include<iostream>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
vector<pil> adjlist[100000];
int V, a, b,visit[100000],ct;
ll c;
pil DFS(int k) {
	visit[k] = ct;
	pil ret(k, 0);
	for (int i = 0; i < adjlist[k].size(); i++) {
		pil next = adjlist[k][i];
		if (visit[next.first] != ct) {
			pil r = DFS(next.first);
			if (ret.second < r.second + next.second) {
				ret.first = r.first;
				ret.second = r.second + next.second;
			}
		}
	}

	return ret;
}
int main() {
	scanf("%d", &V);
	for (int i = 0; i < V; i++) {
		visit[i] = 0;
		scanf("%d%d", &a,&b);
		while (b != -1) {
			scanf("%lld", &c);
			adjlist[a - 1].push_back(pil(b - 1, c));
			scanf("%d", &b);
		}
	}
	ct = 1;
	pil p1=DFS(0);
	ct++;
	pil p2=DFS(p1.first);
	printf("%lld\n", p2.second);
	return 0;
}