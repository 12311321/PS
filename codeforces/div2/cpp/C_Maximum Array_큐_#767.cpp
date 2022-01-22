#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int t, n,k;
queue<int> q[202020];
vector<int> ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i <= n; i++) {
			while (!q[i].empty()) {
				q[i].pop();
			}
		}
		for (int i = 0; i < n; i++) {
			cin >> k;
			q[k].push(i);
		}
		int idx = 0;
		ans.clear();
		while (true) {
			int now = 0;
			int maxIdx = idx;
			
			while (true) {
				while (!q[now].empty() && q[now].front() < idx) {
					q[now].pop();
				}
				if (q[now].empty()) break;
				maxIdx = max(maxIdx, q[now].front());
				now++;
			}

			if (now == 0) break;
			idx = maxIdx+1;
			ans.push_back(now);
		}
		bool flag = false;
		cout << ans.size()+n-idx << "\n";
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		for (int i = idx; i < n; i++) {
			cout << 0 << " ";
		}

		if (ans.size()+n-idx != 0) {
			cout << "\n";
		}
	}
	return 0;
}