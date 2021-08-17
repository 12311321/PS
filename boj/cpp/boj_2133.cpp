#include<iostream>
using namespace std;
int N, dp[30][(1 << 3)];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (1 << 3); j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][3] = 1;
	dp[0][6] = 1;
	dp[0][0] = 1;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < (1 << 3); j++) {
			dp[i][j] += dp[i - 1][7 - j];
		}
		for (int j = 0; j < (1 << 3); j++) {
			if ((j & 3) == 0) {
				dp[i][j | 3] += dp[i][j];
			}
			if ((j & 6) == 0){
				dp[i][j | 6] += dp[i][j];
			}

		}
	}
	
	printf("%d\n", dp[N - 1][7]);
	return 0;
}