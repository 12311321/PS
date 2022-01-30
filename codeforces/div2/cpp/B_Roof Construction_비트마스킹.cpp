#include<iostream>
using namespace std;
int t, n;
bool check[200020];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			check[i] = false;
		}
		int k = 1;
		while (true) {
			if (k * 2 > n - 1) break;
			k *= 2;
		}
		for (int i = n - 1; i >= k; i--) {
			cout << i << " ";
		}
		for (int i = 0; i < k; i++) {
			cout << i << " ";
		}
		cout << "\n";

	}
	return 0;
}