#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

int t, n, k;
pii arr[1010];
bool comp(const pii& p1, const pii& p2) {
	return p1.first < p2.first;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first;
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i].second;
		}
		sort(arr, arr + n, comp);
		
		for (int i = 0; i < n; i++) {
			if (arr[i].first > k) break;
			k += arr[i].second;
		}
		cout << k << "\n";
	}
	return 0;
}