#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;

class SegTree {
	ll* tree;
	int N;
	ll initVal;
	ll(*comp)(ll, ll);
public:
	SegTree(int N, ll initVal, ll(*comp)(ll, ll)) {
		this->N = N;
		this->initVal = initVal;
		this->comp = comp;

		int sz = 1;
		while (sz < N) {
			sz *= 2;
		}
		tree = new ll[sz * 2 + 1];
		for (int i = 0; i <= sz * 2; i++) {
			tree[i] = initVal;
		}
	}
	~SegTree() {
		delete[] tree;
	}

	void updateData(int idx, ll data) {
		int s = 1;
		int e = N;
		int pos = 1;
		while (true) {
		
			if (s == e) {
				tree[pos] = data;
				pos /= 2;
				while (pos > 0) {
					tree[pos] = comp(tree[pos * 2], tree[pos * 2 + 1]);
					pos /= 2;
				}
				break;
			}
			int m = (s + e) / 2;
			if (idx <= m) {
				e = m;
				pos *= 2;
			}
			else {
				s = m + 1;
				pos = pos * 2 + 1;
			}

		}
	}

	ll searchData(int l, int r) {
		return searchData(1, N, 1, l, r);
	}

	ll searchData(int s, int e, int idx, int l, int r) {
		if (s >= l && e <= r) return tree[idx];
		int m = (s + e) / 2;
		ll ret = initVal;
		if (l <= m) {
			ret = comp(ret, searchData(s, m, idx * 2, l, r));
		}
		if (r > m) {
			ret = comp(ret, searchData(m + 1, e, idx * 2 + 1, l, r));
		}
		return ret;
	}
};

int N, Q,query,i;
SegTree* minSegTree, * sumSegTree;
ll timeArr[100001], j;

ll minComp(ll a, ll b) {
	return min(a, b);
}
ll sumComp(ll a, ll b) {
	return a + b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	minSegTree = new SegTree(N, INF, minComp);
	sumSegTree = new SegTree(N, 0, sumComp);
	for (int i = 1; i <= N; i++) {
		cin >> j;
		minSegTree->updateData(i, j);
		sumSegTree->updateData(i, j);
	}
	
	cin >> Q;
	while (Q--) {
		cin >> query >> i >> j;
		if (query == 1) {
			minSegTree->updateData(i, j);
			sumSegTree->updateData(i, j);
		}
		else {
			int s = 1;
			int e = i;
			int l = i;
			while (s <= e) {
				int m = (s + e) / 2;
				ll minVal = minSegTree->searchData(m, i);
				if (j <= minVal) {
					l = m;
					e = m - 1;
				}
				else {
					s = m + 1;
				}
				
			}
			s = i;
			e = N;
			int r = i;
			while (s <= e) {
				int m = (s + e) / 2;
				int minVal = minSegTree->searchData(i, m);
				if (j <= minVal) {
					r = m;
					s = m + 1;
				}
				else {
					e = m - 1;
				}
			}
			cout << sumSegTree->searchData(l, r) << "\n";
		}
	}
	delete minSegTree;
	delete sumSegTree;
}