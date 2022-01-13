#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
int n, l, k,pos[505],lim[505],dp[505][505];
const int INF = (1 << 30);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> l >> k;
	for (int i = 0; i < n; i++) {
		cin >> pos[i];
	}
	pos[n] = l;
	for (int i = 0; i < n; i++) {
		cin >> lim[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (dp[i][j] == INF) break;
			for (int m = 0; m+j <= k; m++) {
				if (i + m + 1 > n) break;
				int nCost = dp[i][j]+(pos[i + m + 1] - pos[i])*lim[i];
				
				dp[i + m + 1][j + m] = min(dp[i + m + 1][j + m], nCost);
			}
		}
	}
	
	int ans = INF;
	for (int i = 0; i <= k; i++) {
		ans = min(ans, dp[n][i]);
	}
	cout << ans << "\n";

	return 0;
}