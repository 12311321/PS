
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll T, K, M, dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
ll GetDig(ll k);
void sol();
int main() {
	scanf("%lld", &T);
	while (T--) {
		sol();
	}
	return 0;
}
ll GetDig(ll k) {
	if (k == 0) {
		return 0;
	}
	ll m = k % 9;
	if (m == 0) {
		return 9;
	}
	else {
		return m;
	}
}

void sol() {
	vector<ll> cycle;
	ll visit[10],sidx,eidx;
	cycle.clear();
	for (int i = 0; i < 10; i++) {
		visit[i] = -1;
	}
	ll pos_x = 0, pos_y = 0;
	scanf("%lld%lld", &K, &M);
	ll gn = 1;
	for (int i = 0; ; i++) {
		ll next = GetDig(gn);
		if (visit[next]!=-1) {
			sidx = visit[next];
			eidx = cycle.size() - 1;
			break;
		}
		visit[next] =i;
		cycle.push_back(next);
		gn = next * M;
	}
	int dn = 0;
	if (K <= sidx) {
		for (int i = 0; i <K; i++) {
			pos_x += dx[i % 4] * cycle[i];
			pos_y += dy[i % 4] * cycle[i];
			dn = (dn + 1) % 4;
		}
	}
	else {
		for (int i = 0; i < sidx; i++) {
			pos_x += dx[i % 4] * cycle[i];
			pos_y += dy[i % 4] * cycle[i];
			dn = (dn + 1) % 4;
		}
		K -= sidx;
		ll cyclesize = eidx - sidx + 1;
		ll cyclenum = K / (cyclesize * 4);
		for (int i = 0; i < cyclesize * 4; i++) {
			pos_x += dx[dn] * cycle[(i % cyclesize) + sidx] * cyclenum;
			pos_y += dy[dn] * cycle[(i % cyclesize) + sidx] * cyclenum;
			dn = (dn + 1) % 4;
		}
		for (int i = 0; i < K % (cyclesize * 4); i++) {
			pos_x += dx[dn] * cycle[(i % cyclesize) + sidx];
			pos_y += dy[dn] * cycle[(i % cyclesize) + sidx];
			dn = (dn + 1) % 4;
		}
	}
	printf("%lld %lld\n", pos_x, pos_y);
}
/*
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll T, K, M, dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
ll GetDig(ll k);
void sol();
int main() {
	scanf("%lld", &T);
	while (T--) {
		sol();
	}
	return 0;
}
ll GetDig(ll k) {
	if (k == 0) {
		return 0;
	}
	ll m = k % 9;
	if (m == 0) {
		return 9;
	}
	else {
		return m;
	}
}

void sol() {
	
	scanf("%lld%lld", &K, &M);
	ll gn = 1,pos_x=0,pos_y=0;
	for (int i = 0; i < K; i++) {
		ll next = GetDig(gn);
		pos_x += dx[i % 4] * next;
		pos_y += dy[i % 4] * next;

		gn = next * M;
	}
	printf("%lld %lld\n", pos_x, pos_y);
}
*/