#include<iostream>
using namespace std;
typedef long long ll;
ll N, M, arr[10000];
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}
	if (N <= M) {
		cout << N << "\n";
		return 0;
	}
	ll s = 0, e = N * 30;
	while (s != e) {
		ll m = (s + e) / 2;
		ll sum = 0;
		for (int i = 0; i < M; i++) {
			sum += (m / arr[i]) + 1;
		}

		if (sum < N) {
			s = m + 1;
		}
		else {
			e = m;
		}


	}

	ll sum;
	do {
		sum = 0;
		s--;
		for (int i = 0; i < M; i++) {
			sum += s / arr[i] + 1;
		}

	} while (sum == N);
	s++;

	ll a = N - sum;
	for (int i = 0; i < M; i++) {
		if (s % arr[i] == 0) {
			a--;
		}
		if (a == 0) {
			cout << i + 1 << "\n";
			break;
		}
	}


	return 0;
}