#include<iostream>
#include<string>
#include<stack>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
const int INF = (1 << 30);
string str;
int dp[1001][5001];
pii pre[1001][5001];
int main() {
	ios::sync_with_stdio(false);
	cin >> str;
	int S = stoi(str.substr(str.find('=') + 1));
	str = str.substr(0, str.find('='));
	for (int i = 0; i <= str.size(); i++) {
		for (int j = 0; j <= S; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	pre[0][0] = pii(-1,-1);
	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j <= S; j++) {
			if (dp[i][j] == INF) continue;
			int val = 0, idx = i;
			while (idx < str.size()) {
				val *= 10;
				val += str[idx] - '0';
				if (j + val > S) {
					break;
				}
				idx++;
				if (dp[idx][j+val] > dp[i][j] + 1) {
					dp[idx][j+val] = dp[i][j] + 1;
					pre[idx][j+val] = pii(i, j);
				}				
			}
		}
	}
	
	stack<int> st;
	pii pos(str.size(), S);
	while (pos.first > 0) {
		st.push(pos.first);
		pos = pii(pre[pos.first][pos.second]);
	}
	for (int i = 0; i < str.size(); i++) {
		if (!st.empty() && i == st.top()) {
			cout << '+';
			st.pop();
		}
		cout << str[i];
	}
	cout << '=' << S << "\n";
	return 0;
}