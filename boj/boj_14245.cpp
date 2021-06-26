#include<iostream>
using namespace std;
class SGT {
public:
	int* tree;
	int* leaf;
	int n;
	SGT(int n) {
		this->n = n;
		int sz = 2;
		while (sz < n) {
			sz *= 2;
		}
		tree = new int[sz * 2];
		for (int i = 1; i < sz * 2; i++) {
			tree[i] = 0;
		}
		leaf = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			Init(i);
		}
	}
	~SGT() {
		delete[] tree;
		delete[] leaf;
	}
	void Init(int idx) {
		int s = 1, e = n, pos = 1;
		while (1) {
			if (s == e) {
				leaf[idx] = pos;
				break;
			}
			int m = (s + e) / 2;
			if (m >= idx) {
				e = m;
			}
			else {
				s = m + 1;
			}
			pos = pos * 2 + (m < idx);
		}
	}
	int Search(int idx) {		
		int pos = leaf[idx];
		int ret =0;
		while (pos >= 1) {
			ret ^= tree[pos];
			pos /= 2;
		}
		return ret;
	}
	void OpXor(int s, int e, int pos, int fs, int fe, int num) {
		if (s == fs && e == fe) {
			tree[pos] ^= num;
			return;
		}
		int m = (s + e) / 2;
		if (m >= fs) {
			OpXor(s, m, pos * 2, fs, fe < m ? fe : m, num);
		}
		if (m < fe) {
			OpXor(m + 1, e, pos * 2 + 1, fs > m+1 ? fs : m+1, fe, num);
		}

	}

};
int n, m, arr[500001],t,a,b,c;
int main() {
	scanf("%d",&n);
	SGT sgt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d%d", &a, &b, &c);
			sgt.OpXor(1, n, 1, a+1, b+1, c);
		}
		else {
			scanf("%d", &a);
			printf("%d\n", arr[a+1] ^ sgt.Search(a+1));
		}
	}
	return 0;
}