#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t, n, m;

int getAbs(int a) {
	return a < 0 ? -a : a;
}
int dist(int r, int c, int r2, int c2) {
	return getAbs(r2 - r) + getAbs(c2 - c);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		vector<int> v;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				v.push_back(max(max(dist(i, j, 0, 0), dist(i, j, n - 1, 0)), max(dist(i, j, n - 1, m - 1), dist(i, j, 0, m - 1))));
			}
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}