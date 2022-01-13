#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

int t, n,a,bit[35];
int gcd(int a, int b) {
	if (a == 0 || b==0) return a+b;
	while (a % b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 0; i < 32; i++) {
			bit[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			cin >> a;
			for (int j = 0; j < 31; j++) {
				if ((a & (1 << j))) {
					bit[j]++;
				}
			}
		}

		int g = bit[0];
		for (int i = 1; i < 31; i++) {
			g = gcd(g, bit[i]);
		}
		if (g == 0) {
			for (int i = 1; i <= n; i++) {
				cout << i << " ";
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (g % i == 0) {
					cout << i << " ";
				}
			}
		}
		cout << "\n";
	}

	return 0;
}