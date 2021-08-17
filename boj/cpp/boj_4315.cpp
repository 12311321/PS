#include <iostream>
#include<vector>
using namespace std;
struct Node {
	int num;
	int par;
	vector<int> child;
};
int n, v, d, c;
Node node[10000];
int ABS(int a) {
	return a < 0 ? -a : a;
}
int DFS(int k) {
	int ret = 0;
	for (int i = 0; i < node[k].child.size(); i++) {
		int next = node[k].child[i];
		ret += DFS(next);
	}
	int pn = node[k].par;
	if (pn != -1) {
		node[pn].num += node[k].num - 1;
		ret += ABS(node[k].num - 1);
	}
	node[k].num = 1;

	return ret;
}
int main() {
	scanf("%d", &n);
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			node[i].par = -1;
			node[i].child.clear();
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &v);
			v--;
			scanf("%d%d", &node[v].num, &d);
			for (int j = 0; j < d; j++) {
				scanf("%d", &c);
				node[v].child.push_back(c - 1);
				node[c - 1].par = v;
			}
		}
		for (int i = 0; i < n; i++) {
			if (node[i].par == -1) {
				printf("%d\n", DFS(i));
				break;
			}
		}

		scanf("%d", &n);
	}
	return 0;
}