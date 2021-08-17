/*

5 5 10
2 2 2 2 2
1 2
2 3
3 4
4 5
5 1

*/
#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
int N, M,s,e;
ll K,dist[1000000];
bool isadj[1000000],visit[1000000];
int main() {
	scanf("%d%d%lld", &N, &M, &K);
	
	for (int i = 0; i < N; i++) {
		scanf("%lld", &dist[i]);
		isadj[i] = true;
		visit[i] = false;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &s, &e);
		if ((s % N) == e-1) {	
			isadj[s - 1] = false;
		}
		else {	
			isadj[e - 1] = false;
		}
		
	}
	queue<int> q;
	int gn = 0;
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			q.push(i);
			ll md = dist[i];
			gn++;
			visit[i] = true;
			while (!q.empty()) {
				int t = q.front();
				q.pop();
				md = md > dist[t] ? dist[t] : md;

				int next = (t + 1) % N;
				if (isadj[t] && !visit[next]) {
					visit[next] = true;
					q.push(next);
				}
				int prev = (N + t - 1) % N;
				if (isadj[prev] && !visit[prev]) {
					visit[prev] = true;
					q.push(prev);
				}
			}
			K -= md;
		}
	}
	if (K >= 0 || gn==1) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}