#include<iostream>
using namespace std;
int n, a[202020], tree[800000] = { 0, }, ans[202020] = { 0, };
const int INF = 1000000007;
int gcd(int a, int b) {
	while (a % b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return b;
}
void insertData(int idx, int k) {
	int s = 1, e = n,pos=1;
	while (true) {
		if (s == e) {
			tree[pos] = k;
			return;
		}
		int m = (s + e) / 2;
		if (m < idx) {
			s = m + 1;
			pos = pos * 2 + 1;
		}
		else {
			e = m;
			pos = pos * 2;
		}
	}
}
void initTree(int s, int e,int pos) {
	if (s == e) return;
	int m = (s + e) / 2;
	initTree(s, m, pos * 2);
	initTree(m + 1, e, pos * 2 + 1);
	tree[pos] = gcd(tree[pos * 2], tree[pos * 2 + 1]);
}

int search(int s, int e, int pos, int fs, int fe) {
	if (s >= fs && e <= fe) {
		return tree[pos];
	}
	int a = -1;
	int b = -1;
	int m = (s + e) / 2;
	if (m >= fs) {
		a = search(s, m, pos * 2, fs, fe);
	}
	if (m < fe) {
		b = search(m + 1, e, pos * 2 + 1, fs, fe);
	}
	if (a == -1) return b;
	else if (b == -1) return a;
	else return gcd(a, b);
}

void updateData(int s, int e, int pos,int idx, int k) {
	if (s == e) {
		tree[pos] = k;
		return;
	}

	int m = (s + e) / 2;
	if (m < idx) {
		updateData(m + 1, e, pos * 2 + 1, idx, k);
	}
	else {
		updateData(s, m, pos * 2, idx, k);
	}
	tree[pos] = gcd(tree[pos * 2], tree[pos * 2 + 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = 1;
		
		insertData(i+1, a[i]);
	}
	initTree(1, n, 1);

	for (int i = 0; i < n; i++) {

		int s = i, e = n - 1, t = -1;
		while (s <= e) {
			int m = (s + e) / 2;
			int g = search(1, n, 1, i+1, m+1);
			if (g == m - i + 1) {
				t = m;
				break;
			}
			else if (g > m - i + 1) s = m + 1;
			else e = m - 1;
		}

		if (t != -1) {
			updateData(1, n, 1, t+1, INF);
			ans[t]++;
		}
	}

	int k = 0;
	for (int i = 0; i < n; i++) {
		k += ans[i];
		cout << k << " ";
	}

	return 0;
}