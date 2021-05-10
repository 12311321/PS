#include<iostream>
using namespace std;
struct Node {
	bool f=true;
	int firstnum=-1;
	int lastnum=-1;
};
class SGT {
public:
	Node* tree;
	int* leaf;
	int N;
	SGT(int N) {
		this->N = N;
		
		Init();
	}
	~SGT() {
		delete[] tree;
		delete[] leaf;
	}
	void Init() {
		int s, e, pos,sz;
		sz = 2;
		while (sz < N) {
			sz *= 2;
		}
		tree = new Node[sz * 2];
		leaf = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			s = 1, e = N, pos = 1;
			while (1) {
				if (s == e) {
					leaf[i] = pos;
					break;
				}
				int m = (s + e) / 2;
				if (m >= i) {
					e = m;
				}
				else {
					s = m + 1;
				}
				pos = pos * 2 + (i> m);
			}
		}
	}
	void Swap(int idx1, int idx2) {
		int a = tree[leaf[idx1]].firstnum;
		int b = tree[leaf[idx2]].firstnum;
		Revise(idx1, b);
		Revise(idx2, a);
	}
	void Revise(int idx, int data) {
		int pos = leaf[idx];
		tree[pos].firstnum = data;
		tree[pos].lastnum = data;
		pos /= 2;
		while (pos > 0) {
			int lc = pos * 2;
			int rc = pos * 2 + 1;
			if (tree[lc].f && tree[rc].f && tree[lc].lastnum<=tree[rc].firstnum) {
				tree[pos].f = true;
				tree[pos].firstnum = tree[lc].firstnum;
				tree[pos].lastnum = tree[rc].lastnum;
			}
			else {
				tree[pos].f = false;
			}
			pos /= 2;
		}
	}
	Node Search(int s, int e, int pos, int fs, int fe) {
		
		if (s == fs && e == fe) {
			return tree[pos];
		}
		Node ret;
		int m = (s + e) / 2;
		if (fe <= m) {
			ret= Search(s, m, pos * 2, fs, fe);
			
		}
		else if (fs >= m + 1) {
			ret = Search(m + 1, e, pos * 2 + 1, fs, fe);
		}
		else {
			ret = Search(s, m, pos * 2, fs, m);
			Node r = Search(m + 1, e, pos * 2 + 1, m + 1, fe);
			if (ret.f && r.f && ret.lastnum <= r.firstnum) {
				ret.f = true;
				ret.lastnum = r.lastnum;
			}
			else {
				ret.f = false;
			}
		}
		return ret;
	}
	
};
int N, M,Q,L,R;
int main() {
	scanf("%d%d", &N, &M);
	SGT sgt(N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &Q);
		sgt.Revise(i, Q);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &Q, &L, &R);
		if (Q == 1) {
			if (sgt.Search(1, N, 1, L, R).f) {
				printf("CS204\n");
			}
			else {
				printf("HSS090\n");
			}
		}
		else {
			sgt.Swap(L, R);
		}
	}
	return 0;
}