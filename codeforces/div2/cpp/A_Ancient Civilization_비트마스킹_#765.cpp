#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int t, n, l,x,arr[32];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> l;
		for (int i = 0; i < l; i++) {
			arr[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> x;
			for (int j = 0; j < l; j++) {			
				if ((x & (1 << j)) != 0) {
					arr[j]++;
				}
			}
			
		}
		
		int ans = 0;
		for (int i = 0; i < l; i++) {
			
			if (arr[i] > n / 2) {
				ans |= (1 << i);
			}	
		}
		cout << ans << "\n";

	}


	return 0;
}