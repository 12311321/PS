#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef long long ll;
int N;
ll arr[6];
unordered_map<int, unordered_set<ll>> umap[7];

bool isPrime(ll num) {
	if (num < 2) return false;
	ll t = 2;
	while (t * t <= num) {
		if (num % t == 0) return false;
		t++;
	}

	return true;
}

int main() {
	scanf("%d", &N);
	ll minAns = -1;
	ll maxAns = -1;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
		umap[1][1 << i] = (unordered_set<ll>());
		umap[1][1 << i].insert(arr[i]);
	}

	for (int sz = 2; sz <= N; sz++) {
		for (int i = 1; i <sz; i++) {	
			for (auto sIter = umap[i].begin(); sIter != umap[i].end(); sIter++) {
				for (auto eIter = umap[sz - i].begin(); eIter != umap[sz - i].end(); eIter++) {
					int andBit = ((*sIter).first & (*eIter).first);
					int orBit = ((*sIter).first | (*eIter).first);
					if (andBit!= 0) continue;	
					if (umap[sz].count(orBit) == 0) umap[sz][orBit] = unordered_set<ll>();
					for (auto ssIter = (*sIter).second.begin(); ssIter != (*sIter).second.end(); ssIter++) {
						for (auto esIter = (*eIter).second.begin(); esIter != (*eIter).second.end(); esIter++) {
							if (sz != N) {
								umap[sz][orBit].insert((*ssIter) * (*esIter));
							}
							umap[sz][orBit].insert((*ssIter) + (*esIter));
							umap[sz][orBit].insert((*ssIter) - (*esIter));
							if ((*esIter) != 0) {
								umap[sz][orBit].insert((*ssIter) / (*esIter));
							}
						}

					}

				}
			}
		}
	}

	for (auto iter = umap[N][(1<<N)-1].begin(); iter!= umap[N][(1 << N) - 1].end(); iter++){
		if (!isPrime(*iter)) continue;
		minAns = (minAns == -1) ? (*iter) : min(minAns, (*iter));
		maxAns = (maxAns == -1) ? (*iter) : max(maxAns, (*iter));
	}

	if (minAns == -1) printf("%lld\n", minAns);
	else printf("%lld\n%lld\n", minAns, maxAns);

	return 0;
}
