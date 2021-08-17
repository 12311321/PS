#include<iostream>
using namespace std;
int sz, m, n, A[1000], B[1000],dp_A[2000001],dp_B[2000001],sum;
int main() {
	scanf("%d%d%d", &sz,&m,&n);
	for (int i = 0; i <= sz; i++) {
		dp_A[i] = 0;
		dp_B[i] = 0;
	}
	sum = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", &A[i]);
		sum += A[i];
	
	}
	if (sum <= sz) {
		dp_A[sum]++;
	}
	sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
		sum += B[i];
		
	}
	if (sum <= sz) {
		dp_B[sum]++;
	}
	dp_B[0] = 1;
	dp_A[0] = 1;
	for (int i = 0; i < m; i++) {
		sum = 0;
		for (int j = 0; j < m-1; j++) {
			sum += A[(i + j) % m];
			if (sum > sz) {
				break;
			}
			dp_A[sum]++;
		}
	}
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n-1; j++) {
			sum += B[(i + j) % n];
			if (sum > sz) {
				break;
			}
			dp_B[sum]++;
		}
	}
	long long answer = 0;
	for (int i = 0; i <= sz; i++) {
		answer += ((long long)dp_A[i] * (long long)dp_B[sz - i]);
	}
	printf("%lld\n", answer);
	return 0;
}