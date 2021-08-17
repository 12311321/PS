#include<iostream>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
struct Node {
	int h;
	pii left;
	pii right;
};
class SGT {
public:
	int N;
	int* tree;
	Node *node;
	SGT(int N) {
		this->N = N;
		int sz = 2;
		while (sz < N) {
			sz *= 2;
		}
		tree = new int[sz * 2];
		node = new Node[N + 1];
		for (int i = 1; i < sz * 2; i++) {
			tree[i] = 0;
		}
		for (int i = 1; i <= N; i++) {
			node[i].h = -1;
		}
	}
	~SGT() {
		delete[] tree;
		delete[] node;
	}
	void InsertRoot(int k) {
		node[k].h = 1;
		node[k].left = pii(1, k - 1);
		node[k].right = pii(k + 1, N);
		Divide(1, N, 1, 1, k - 1, -k);
		Divide(1, N, 1, k + 1, N, k);
	}
	int SearchParent(int s, int e, int pos, int k) {
		if (tree[pos] != 0) {
			return tree[pos];
		}
		int m = (s + e) / 2;
		if (m >= k) {
			return SearchParent(s, m, pos * 2, k);
		}
		else {
			return SearchParent(m + 1, e, pos * 2 + 1, k);
		}
	}
	void Divide(int s, int e, int pos, int fs, int fe,int data) {	
		if (fs > fe) {
			return;
		}
		if (s==fs && e==fe) {
			tree[pos] = data;
			return;
		}
		tree[pos] = 0;
		int m = (s + e) / 2;
		if (m >= fs) {
			Divide(s, m, pos * 2, fs, m > fe ? fe : m, data);
		}
		if (m < fe) {
			Divide(m + 1, e, pos * 2 + 1, m + 1 < fs ? fs : m + 1, fe, data);
		}

	}
	void InsertData(int k) {
		int par = SearchParent(1,N,1,k);//음수일경우 par의 left, 양수일 경우 right
		if (par < 0) {
			node[k].h = node[-par].h + 1;
			node[k].left = node[-par].left;
			node[k].right = node[-par].left;	
		}
		else {
			node[k].h = node[par].h + 1;
			node[k].left = node[par].right;
			node[k].right = node[par].right;	
			
		}
		node[k].left.second = k - 1;
		node[k].right.first = k + 1;
		Divide(1, N, 1, node[k].left.first, node[k].left.second,-k);
		Divide(1, N, 1, node[k].right.first, node[k].right.second,k);
		
	}
};

int N,P;
int main() {
	scanf("%d", &N);
	SGT sgt(N);
	scanf("%d", &P);
	sgt.InsertRoot(P + 1);
	for (int i = 1; i < N; i++) {
		scanf("%d", &P);
		sgt.InsertData(P + 1);
	}
	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += sgt.node[i].h;
	}
	printf("%lld\n", ans);
	return 0;

}