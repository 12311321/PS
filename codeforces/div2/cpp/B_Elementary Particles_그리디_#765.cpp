#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
int t, n, a[150000];
vector<int> arr[150001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		int maxVal = -1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			maxVal = max(maxVal, a[i]);
		}
		for (int i = 1; i <= maxVal; i++) {
			arr[i].clear();
		}
		for (int i = 0; i < n; i++) {
			arr[a[i]].push_back(i);
		}
		int ans = -1;
		for (int i = 1; i <= maxVal; i++) {
			if (arr[i].size() >= 2) {
				for (int j = 0; j < arr[i].size() - 1; j++) {
					int k = arr[i][j] + n - 1 - arr[i][j+1];
					ans = max(ans, k + 1);
				}
				
			}
		}
		cout << ans << "\n";
	}

	return 0;
}