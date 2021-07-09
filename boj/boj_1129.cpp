#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, length[50],mdist;
bool visit[50][50];
bool DFS(int a, int b,int idx);
vector<int> ans[2];
int main() {
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &length[i]);
		for (int j = 0; j < N; j++) {
			visit[i][j] = false;
		}
	}
	
	sort(length, length + N);
	if (N <= 2) {
		for (int i = 0; i < N; i++) {
			printf("%d ", length[i]);
		}
		return 0;
	}
	mdist = 0;
	for (int i = 2; i < N; i++) {
		mdist = max(mdist,length[i] - length[i - 2]);
	}
	DFS(0, 0,1);
	printf("%d ", length[0]);
	for (int i = ans[0].size()-1; i >= 0; i--) {
		printf("%d ", ans[0][i]);
	}
	for (int i = 0; i < ans[1].size(); i++) {
		printf("%d ", ans[1][i]);
	}
	printf("\n");
	return 0;
}
bool DFS(int a, int b,int idx) {
	if (idx == N - 1) {
		if (length[idx] - length[a] <= mdist && length[idx] - length[b] <= mdist) {
			ans[1].push_back(length[idx]);
			return true;
		}
		else {
			return false;
		}
	}
	if (visit[a][b]) {
		return false;
	}
	visit[a][b] = true;
	//시계방향
	if (length[idx] - length[a] <= mdist) {
		bool r = DFS(idx, b, idx + 1);
		if (r) {
			ans[0].push_back(length[idx]);
			return true;
		}
	}

	//반시계방향
	if (length[idx] - length[b] <= mdist) {
		bool r = DFS(a, idx, idx + 1);
		if (r) {
			ans[1].push_back(length[idx]);
			return true;
		}
	}

	return false;
}

