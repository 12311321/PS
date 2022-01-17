#include<iostream>
#include<string>
using namespace std;
typedef pair<int, int> pii;
int t, n, m, r, c;
string arr[99];
int visit[52][52];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> m >> r >> c;
		int bcnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			arr[i] = ' ' + arr[i];
			for (int j = 1; j <= m; j++) {
				bcnt += (arr[i][j] == 'B');
			}
		}
		if (arr[r][c] == 'B') {
			cout << 0 << "\n";
		}
		else {
			bool flag = false;
			for (int i = 1; i <= n; i++) {
				if (arr[i][c] == 'B') {
					cout << 1 << "\n";
					flag = true;
					break;
				}
			}
			if (flag) continue;
			for (int j = 1; j <= m; j++) {
				if (arr[r][j] == 'B') {
					cout << 1 << "\n";
					flag = true;
					break;
				}
			}
			if (flag) continue;
			if (bcnt == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << 2 << "\n";
			}
		}	
	}


	return 0;
}