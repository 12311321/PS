#include<iostream>
#include<vector>
using namespace std;
int n, k,num;
struct Node {
	int par;
	vector<int> child;
};
Node node[1000001];
int input[1000];
int Search(int k) {
	int par = node[k].par;
	if (par == -1) {
		return 0;
	}
	int gpar = node[par].par;
	if (gpar == -1) {
		return 0;
	}
	int ret = 0;
	for (int i = 0; i < node[gpar].child.size(); i++) {
		int uncle = node[gpar].child[i];
		if (uncle != par) {
			ret += node[uncle].child.size();
		}
	}
	return ret;
}
int main() {
	for (int i = 1; i <= 1000000; i++) {
		node[i].par = -1;
		node[i].child.clear();
	}
	scanf("%d%d", &n, &k);
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &input[i]);
			node[input[i]].par = -1;
			node[input[i]].child.clear();
		}
		int idx = -1;
		for (int i = 1; i < n; i++) {
			if (input[i] > input[i - 1] + 1) {
				idx++;
			}
			node[input[i]].par = input[idx];
			node[input[idx]].child.push_back(input[i]);
		}

		printf("%d\n", Search(k));


		scanf("%d%d", &n, &k);
	}
	return 0;
}