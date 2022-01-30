#include<iostream>
using namespace std;
int t, n,k,a[60000],b[60000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n / 2; i++) {
			a[i] = i;
			b[i] = n-1 - i;
		}

		if (k == n - 1) {
			if (n == 4) {
				cout << -1 << "\n";
				continue;
			}
			else {
				b[0] = 1;
				a[1] = n - 1;
				b[2] = n - 1 - 3;
				b[3] = n - 1 - 2;
			}
			
		}
		else {
			a[0] = k;
			if (k >= n / 2) {
				b[n - 1 - k] = 0;
			}
			else {
				a[k] = 0;
			}
			
		}
		for (int i = 0; i < n / 2; i++) {
			cout << a[i] << " " << b[i] << "\n";	
		}

	}
	return 0;
}