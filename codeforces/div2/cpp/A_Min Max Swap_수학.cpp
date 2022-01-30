#include<iostream>
#include<algorithm>
using namespace std;
int t, n, a[110],b[110];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		int maxA = 0;
		int maxB = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < b[i]) {
				maxA = max(maxA, b[i]);
				maxB = max(maxB, a[i]);
			}
			else {
				maxA = max(maxA, a[i]);
				maxB = max(maxB, b[i]);
			}
		}
		cout << maxA * maxB << "\n";
		
	}
	return 0;
}