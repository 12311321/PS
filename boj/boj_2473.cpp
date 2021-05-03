#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long ll;
int N;
ll arr[5000];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);

	}
	sort(arr, arr + N);
	ll answer[4];
	answer[0] = (ll)1000000000 * 3;
	for (int i = 0; i < N - 2; i++) {
		ll sum;
		int a = i + 1;
		int b = N - 1;
		while (a < b) {
			
			
			sum = arr[i] + arr[a] + arr[b];
			if (answer[0] > abs(sum)) {
				answer[0] = abs(sum);
				answer[1] = arr[i];
				answer[2] = arr[a];
				answer[3] = arr[b];
			}
			if (sum < 0) {
				a++;
			}
			else {
				b--;
			}
		}
	}
	printf("%lld %lld %lld\n", answer[1], answer[2], answer[3]);
	return 0;
}