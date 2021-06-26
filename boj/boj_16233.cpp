#include<iostream>
using namespace std;
typedef long long ll;
const ll MAX_VAL = 1000000000;
int T;
ll N;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &N);
		ll ans = 0;
		ll ex = MAX_VAL;
		while (ex >1) {
			ll s = 0, e = 9,n;
			while (s<=e) {
				ll m = (s + e) / 2;
				if (N + m >=ans + m * ex) {
					n = m;
					s = m + 1;
				}
				else {
					e=m-1;
				}		
			}
			
			N += n;
			ans += ex * n;
			ex /= 10;
		}
		
		printf("%lld ", (ans == N) ? ans : -1);
		
	}
	return 0;
}
