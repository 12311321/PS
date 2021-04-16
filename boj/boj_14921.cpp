#include<iostream>
#include<cstdlib>
using namespace std;
int N, A[100000];

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int p1 = 0, p2 = N - 1;
	int answer = 100000000*2+1;
	while (p1 != p2) {
		int t = A[p1] + A[p2];
		if (abs(t) < abs(answer)) {
			answer = t;
		}
		if (t < 0) {
			p1++;
		}
		else {
			p2--;
		}
		

	}
	cout << answer << "\n";
	return 0;
}