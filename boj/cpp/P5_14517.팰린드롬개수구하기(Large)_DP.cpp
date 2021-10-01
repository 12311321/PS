#include<iostream>
#include<string>
using namespace std;
const int MOD = 10007;
string s;
int dp[1000][1000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		dp[i][i] = 1;
	}
	for (int i = 0; i < s.size() - 1; i++) {
		dp[i][i + 1] = 2 + (s[i] == s[i + 1]);
	}
	for (int length = 3; length <= s.size(); length++) {
		for (int sidx = 0; sidx <= s.size() - length; sidx++) {
			if (s[sidx] == s[sidx + length - 1]) {
				dp[sidx][sidx + length - 1] = dp[sidx + 1][sidx + length - 2] + 1;
			}
			else {
				dp[sidx][sidx + length - 1] = 0;
			}

			dp[sidx][sidx + length - 1] += dp[sidx + 1][sidx + length - 1] + dp[sidx][sidx + length - 2] - dp[sidx + 1][sidx + length - 2] + MOD;
			dp[sidx][sidx + length - 1] %= MOD;
		}

	}

	cout << dp[0][s.size() - 1] << "\n";
	return 0;
}
