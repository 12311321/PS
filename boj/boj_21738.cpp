#include<iostream>
#include<vector>
using namespace std;
const int INF = (1 << 30);
int N, S,P,A,B,dist[328000];
vector<int> adjlist[328000];
bool visit[328000];
void DFS(int k) {
	visit[k] = true;
	if (k < S) {
		dist[k] = 1;
		return;
	}
	for (int i = 0; i < adjlist[k].size(); i++) {
		int next = adjlist[k][i];
		if (!visit[next]) {
			DFS(next);
			dist[k] = dist[k] > dist[next] + 1 ? dist[next] + 1 : dist[k];
		}
	}

}
int main() {
	scanf("%d%d%d", &N, &S, &P);
	for (int i = 0; i < N; i++) {
		dist[i] = INF;
		visit[i] = false;
	}

	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d", &A, &B);
		adjlist[A - 1].push_back(B - 1);
		adjlist[B - 1].push_back(A - 1);
		
	}
	
	DFS(P - 1);
	int ans[2] = { INF,INF };
	for (int i = 0; i < adjlist[P - 1].size(); i++) {
		int next = adjlist[P - 1][i];
		if (ans[0] > dist[next]) {
			ans[1] = ans[0];
			ans[0] = dist[next];
		}
		else if (ans[1] > dist[next]) {
			ans[1] = dist[next];
		}
	}
	printf("%d\n", N - ans[0] - ans[1]-1);
	return 0;
}