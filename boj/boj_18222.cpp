/*

01101001

*/
#include<iostream>
using namespace std;
typedef long long ll;
ll k;
int main() {
		scanf("%lld", &k);
		bool f = false;
		while (k > 1) {
			ll t = 1;
			
			while (t * 2 < k) {
				t *= 2;
			}
			//t= (k보다 작은 2의 제곱수)
			f = !f;
			k = k - t;
		}
		if (f) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	
	return 0;
}