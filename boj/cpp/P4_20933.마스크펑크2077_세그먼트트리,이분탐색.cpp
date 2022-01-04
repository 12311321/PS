#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;

class SegTree {
	ll* tree;
	int N;
	ll initVal;
	ll(*todo)(ll, ll);
public:
	SegTree(int N, ll initVal, ll (*todo)(ll, ll)) {
		this->N = N;
		this->initVal = initVal;
		this->todo = todo;
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

	void insert(int idx, ll data) {
		int s = 1;
		int e = N;
		int pos = 1;
		while (true) {	
			tree[pos] = todo(tree[pos], data);
			if (s == e) break;
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

	ll searchValue(int fs, int fe) {
		return searchValue(1, N, 1, fs, fe);
	}

	ll searchValue(int s, int e, int idx, int fs, int fe) {
		if (s >= fs && e <= fe) return tree[idx];
		int m = (s + e) / 2;
		ll ret = initVal;
		if (fs <= m) {
			ret = todo(ret, searchValue(s, m, idx * 2, fs, fe));
		}
		if (fe > m) {
			ret = todo(ret, searchValue(m + 1, e, idx * 2 + 1, fs, fe));
		}
		return ret;
	}
};

int N, Q, target;
SegTree *minSegTree, *sumSegTree;
ll timeArr[100001], k;
string query;

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
	minSegTree =new SegTree(N, INF ,minComp);
	sumSegTree =new SegTree(N - 1, 0, sumComp);
	for (int i = 1; i <= N; i++) {
		cin >> k;
		minSegTree->insert(i, k);
	}
	for (int i = 1; i <= N - 1; i++) {
		cin >> timeArr[i];
		sumSegTree->insert(i, timeArr[i]);
	}
	cin >> Q;
	while (Q--) {
		cin >> query>>target>>k;
		if (query[0] == 'C') {
			int s = 1;
			int e = target - 1;
			int l = target;
			int r = target - 1;
			while (s <= e) {
				int m = (s + e) / 2;
				ll res = sumSegTree->searchValue(m, target - 1);
				if (res <= k) {
					l = m;
					e = m - 1;
				}
				else {
					s = m + 1;
				}

			}
			s = target;
			e = N - 1;
			while (s <= e) {
				int m = (s + e) / 2;
				ll res = sumSegTree->searchValue(target, m);
				if (res <= k) {
					r = m;
					s = m + 1;
				}
				else {
					e = m - 1;
				}
			}
			cout << minSegTree->searchValue(l, r + 1) << "\n";
		}
		else {
			sumSegTree->insert(target, k - timeArr[target]);
			timeArr[target] = k;
		}

	}
	delete minSegTree;
	delete sumSegTree;
}