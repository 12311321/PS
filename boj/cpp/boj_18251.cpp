#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const ll INF = ((ll)1 << 60);
int N,cnt,max_h;
ll PBT[262144],ans;
pli SortedXPos[262144];
void Inorder(int k,int h);
ll Search(ll a, ll b);
int main() {
	scanf("%d", &N);
	max_h = log2(N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &PBT[i]);
	}
	cnt = 0;
	Inorder(1, 0);
	ans = -INF;
	for (int i = 0; i <= max_h; i++) {
		for (int j = i; j <= max_h; j++) {
			ans = max(ans, Search(i, j));
		}
	}
	printf("%lld\n", ans);
	return 0;
}
void Inorder(int k,int h) {
	if (k > N) {
		return;
	}
	Inorder(k * 2,h+1);
	SortedXPos[++cnt] = pli(PBT[k], h);
	Inorder(k * 2 + 1,h+1);
}
ll Search(ll a, ll b) {
	ll max_val = -INF,nval= -INF;

	for (int i = 1; i <= N; i++) {
		if (SortedXPos[i].second<a || SortedXPos[i].second>b) continue;
		nval= max(nval + SortedXPos[i].first, SortedXPos[i].first);
		max_val = max(max_val, nval);

	}
	return max_val;
}