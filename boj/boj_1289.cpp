#include<iostream>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
const ll MOD = 1000000007;
int N,s,e;
ll w,answer;
vector<pil> adjlist[100000];
bool visit[100000];

ll DFS(int k) {
	visit[k] = true;
	vector<ll> sum;
	sum.push_back(0);
	ll ret = 1;
	for (int i = 0; i < adjlist[k].size(); i++) {
		int next = adjlist[k][i].first;
		ll w = adjlist[k][i].second;
		if (!visit[next]) {		
			ll r = DFS(next);
			
			ret += (r*w)%MOD;
			ret %= MOD;
			sum.push_back((sum.back()+((r*w)%MOD)) % MOD);
		}
	}
	
	for (int i = 1; i < sum.size(); i++) {
		answer += (MOD+sum[i] - sum[i - 1])%MOD * (MOD+sum.back() - sum[i]+1)%MOD;
		answer %= MOD;
	}
	return ret;

}
int main() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		scanf("%d%d%lld", &s, &e, &w);
		adjlist[s - 1].push_back(pil(e - 1, w));
		adjlist[e - 1].push_back(pil(s - 1, w));
		visit[i] = false;
	}
	answer = 0;
	DFS(0);
	printf("%lld\n", answer);
	return 0;
}