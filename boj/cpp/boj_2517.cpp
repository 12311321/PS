#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
class SGT {
public:
	int* tree;
	int N;
	SGT(int N) {
		this->N = N;
		int sz = 2;
		while (sz < N) {
			sz *= 2;
		}
		tree = new int[sz * 2];
		for (int i = 1; i < sz * 2; i++) {
			tree[i] = 0;
		}
	}
	~SGT() {
		delete[] tree;
	}
	void InsertData(int idx) {
		int s = 1, e = N, pos = 1;
		while (1) {
			tree[pos]++;
			if (s == e) {
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
	int Search(int s) {
		return Search(1, N, 1, 1, s);
	}
	int Search(int s, int e, int pos, int fs, int fe) {
		int ret = 0;
		if (s == fs && e == fe) {
			return tree[pos];
		}
		int m = (s + e) / 2;
		if (m >= fs) {
			ret += Search(s, m, pos * 2, fs, fe < m ? fe : m);
		}
		if (m < fe) {
			ret += Search(m + 1, e, pos * 2 + 1, m + 1 < fs ? fs : m + 1, fe);
		}
		return ret;
	}
};
int N,ans[500000];
pii arr[500000];
int main() {
	scanf("%d", &N);
	SGT sgt(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i+1;
	}
	sort(arr, arr + N);
	for (int i =0; i <N; i++) {
		int idx = arr[i].second;
		ans[idx - 1] = idx-sgt.Search(idx);
		sgt.InsertData(idx);
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}