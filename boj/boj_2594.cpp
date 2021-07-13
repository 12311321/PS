#include <iostream>
#include<string>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
struct CompTime {
	bool operator()(pii t1, pii t2) {
		return t1.second > t2.second;
	}
};
int N;
string s;
pii t[50];
priority_queue<pii, vector<pii>, CompTime> pq;
int RetTime(string s);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		t[i].first = RetTime(s) - 10;
		cin >> s;
		t[i].second = RetTime(s) + 10;
	}
	sort(t, t + N);
	int ans = 0;
	int ntime = RetTime("1000");
	for (int i = 0; i < N; i++) {
		while (!pq.empty() && pq.top().second <= t[i].first) {
			ntime = pq.top().second;
			pq.pop();
		}
		if (pq.empty()) {

			ans = max(ans, t[i].first - ntime);
		}
		ntime = t[i].first;
		pq.push(t[i]);
	}
	while (!pq.empty()) {
		ntime = pq.top().second;
		pq.pop();
	}
	ans = max(ans, RetTime("2200") - ntime);
	cout << ans << "\n";
	return 0;
}
int RetTime(string s) {
	int h = (s[0] - '0') * 10 + (s[1] - '0');
	int m = (s[2] - '0') * 10 + (s[3] - '0');
	return h * 60 + m;
}