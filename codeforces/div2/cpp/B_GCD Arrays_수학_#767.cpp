#include<iostream>
using namespace std;
int t, l, r, k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> l >> r >> k;	
		if(l==r){
			if (l == 1) {
				cout << "NO\n";
			}
			else {
				cout << "YES\n";
			}
		}
		else {
			int n;
			if ((r - l + 1) % 2) {
				n = (r - l + 1) / 2 + (l % 2);
				
			}
			else {
				n = (r - l + 1) / 2;
			}

			if (n <= k) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}