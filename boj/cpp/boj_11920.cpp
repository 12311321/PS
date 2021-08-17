#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int N, K, arr[100000],arrIdx[100000];

bool comp(int a, int b) {
	return arr[a] > arr[b];
}
int main() {
	stack<int> ans;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		arrIdx[i] =i;
	
	}
	int idx = 0;
	int empty = 0;
	sort(arrIdx, arrIdx + N, comp);

	for (int i = N - 1; i >= 0; i--) {
		if (arr[i] == -1) {
			empty--;
			continue;
		}
		int ct = 0;
		for (int j = 0; j < K - empty; j++) {
			while (idx < N && arr[arrIdx[idx]] == -1) {
				idx++;
			}
			if (idx == N || arr[arrIdx[idx]]<=arr[i]) break;

			ct++;
			ans.push(arr[arrIdx[idx]]);
			arr[arrIdx[idx]] = -1;
			idx++;
		}
		empty += ct;
		ans.push(arr[i]);
		arr[i] = -1;
	}

	while (!ans.empty()) {
		printf("%d ",ans.top());
		ans.pop();
	}

	return 0;
}