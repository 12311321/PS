#include<iostream>
using namespace std;
typedef long long ll;
ll N,arr[3000];
bool f[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	ll answer = 0;
	for (int i = 0; i <= arr[N - 1]; i++) {
		f[i] = false;
	}
	for (int i = 0; i < N; i++) {
		f[arr[i]] = true;
	}
	for (int i = 0; i < N-2; i++) {
		for (int j = i + 1; j < N-1; j++) {
			ll dist = arr[j] - arr[i];
			ll ct = arr[j] + arr[i];
			int pos = arr[j]+dist;
			bool f2 = false;
			while (pos <= arr[N - 1] && f[pos]) {
				ct += pos;
				f2 = true;
				pos += dist;
			}
			if (f2) {
				answer = answer < ct ? ct : answer;
			}
		}
	}
	cout << answer << "\n";

	return 0;
}