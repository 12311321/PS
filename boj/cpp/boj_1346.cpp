#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Sinfo {
	int C;
	int X;
	int Y;
	int L;
};
int N, K,dp[100],sum[100];
Sinfo sinfo[100];
int ExDist(const Sinfo& s1, const Sinfo& s2);
bool CompPos(const Sinfo& s1, const Sinfo& s2);
bool YposJump(int a, int b);
vector<int> adj[100];
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &sinfo[i].C, &sinfo[i].X, &sinfo[i].Y, &sinfo[i].L);
		dp[i] = -1;
		sum[i] = 0;
	}
	sort(sinfo, sinfo + N, CompPos);
	
	int ct = 0;
	adj[ct].push_back(0);
	sum[ct] += sinfo[0].C;
	for (int i = 1; i < N; i++) {
		if (ExDist(sinfo[i - 1], sinfo[i]) > K * K || sinfo[i - 1].Y != sinfo[i].Y) {
			ct++;
		}
		sum[ct] += sinfo[i].C;
		adj[ct].push_back(i);
	}
	int ans = 0;
	
	for (int i = 0; i <= ct; i++) {


		if (sinfo[adj[i][0]].Y <= K) {
			dp[i] = max(dp[i], sum[i]);
			ans = max(ans, dp[i]);
		}
		if (dp[i] == -1) continue;
		for (int j = i + 1; j <= ct; j++) {

			if (YposJump(i, j)) {
				dp[j] = max(dp[j], dp[i] + sum[j]);
				ans = max(ans, dp[j]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
int ExDist(const Sinfo& s1, const Sinfo& s2) {
	int s1_x=s1.X, s1_y=s1.Y, s2_x=s2.X, s2_y=s2.Y;
	if (s1.X + s1.L < s2.X) {
		s1_x += s1.L;
	}
	else if (s2.X + s2.L < s1.X) {
		s2_x += s2.L;
	}
	else {
		return (s1.Y - s2.Y) * (s1.Y - s2.Y);
	}

	return (s1_x - s2_x) * (s1_x - s2_x) + (s1_y - s2_y) * (s1_y - s2_y);
}
bool CompPos(const Sinfo& s1, const Sinfo& s2) {
	if (s1.Y == s2.Y) {
		return s1.X < s2.X;
	}
	else {
		return s1.Y < s2.Y;
	}
}
bool YposJump(int a, int b) {
	int ypos_a = sinfo[adj[a][0]].Y;
	int ypos_b = sinfo[adj[b][0]].Y;
	if (ypos_a >= ypos_b) {
		return false;
	}
	for (int i = 0; i < adj[a].size(); i++) {
		for (int j = 0; j < adj[b].size(); j++) {
			if (ExDist(sinfo[adj[a][i]], sinfo[adj[b][j]]) <= K * K) {
				return true;
			}
		}
	}

	return false;
	
}
