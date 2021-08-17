#include<iostream>
#include<string>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
const int MOD = 1000000007;
int N, M, L,dp[2][300][300],minussum[2][300];
string s,map[300];
vector<pii> alppos[26];
pii dir[4] = { pii(2,2),pii(2,-2),pii(-2,2),pii(-2,-2) };
void Reset(int(&arr)[300][300], int (&arr2)[2][300]);
void Search(int idx);
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M >> L>>s;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		
		for (int j = 0; j < M; j++) {
			dp[0][i][j] = 0;
			dp[1][i][j] = 0;
			alppos[map[i][j] - 'A'].push_back(pii(i, j));
			if (map[i][j] == s[0]) {
				dp[0][i][j] = 1;
			}
		}
	}
	
	for (int i = 1; i < s.size(); i++) {
		Reset(dp[i % 2], minussum);
		Search(i);
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans += dp[(s.size() - 1) % 2][i][j];
			ans %= MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}

void Reset(int(&arr)[300][300], int(&arr2)[2][300]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		arr2[0][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		arr2[1][i] = 0;
	}
}
void Search(int idx) {
	int pasc = s[idx - 1] - 'A';
	int sum = 0;
	for (int i = 0; i < alppos[pasc].size(); i++) {
		pii pos = alppos[pasc][i];
		sum += dp[1 - (idx % 2)][pos.first][pos.second];
		sum %= MOD;
		for (int j = 0; j < 4; j++) {
			
			int nr = pos.first + dir[j].first;
			int nc = pos.second + dir[j].second;
			
			if (nr < 0 || nr >= N || nc < 0 || nc >= M || map[nr][nc]!=s[idx]) continue;
			dp[idx % 2][nr][nc] += (MOD - dp[1 - (idx % 2)][pos.first][pos.second])%MOD;
			dp[idx % 2][nr][nc] %= MOD;
			
		}
		for (int j = -1; j <= 1; j++) {
			for (int k = -1; k <= 1; k++) {
				
				int nr = pos.first + j;
				int nc = pos.second + k;
				if (nr < 0 || nr >= N || nc < 0 || nc >= M || map[nr][nc] != s[idx]) continue;
				dp[idx % 2][nr][nc] += dp[1 - (idx % 2)][pos.first][pos.second];
				dp[idx % 2][nr][nc] %= MOD;
			}
		}
		for (int j = -1; j <= 1; j++) {
			
			int nr = pos.first + j;
			int nc = pos.second + j;
			
			if (nr >= 0 && nr < N) {
				minussum[0][nr] += dp[1 - (idx % 2)][pos.first][pos.second];
				minussum[0][nr] %= MOD;
			}
			if (nc >= 0 && nc < M) {
				minussum[1][nc] += dp[1 - (idx % 2)][pos.first][pos.second];
				minussum[1][nc] %= MOD;
			}
			
		}
		
		
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == s[idx]) {
				dp[idx % 2][i][j] += sum;
				dp[idx % 2][i][j] %= MOD;
				dp[idx % 2][i][j] += (MOD - minussum[0][i]) % MOD;;
				dp[idx % 2][i][j] %= MOD;
				dp[idx % 2][i][j] += (MOD - minussum[1][j]) % MOD;;
				dp[idx % 2][i][j] %= MOD;
			}
		}
	}
}
