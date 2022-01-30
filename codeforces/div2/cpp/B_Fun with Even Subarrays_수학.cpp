#include<iostream>
using namespace std;
int t, n, a[200200];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = n-1; i>=0; i--) {
			cin >> a[i];
		}
		int ans = 0;
		int idx = 1;
		while (idx <= n - 1) {
			if (a[idx] != a[0]) {
				ans++;
				idx += idx;
			}
			else {
				idx++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}