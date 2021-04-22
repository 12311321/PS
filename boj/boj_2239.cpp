#include<iostream>
#include<string>
using namespace std;
bool bit[3][9][9];
string s[9];
bool DFS(int r, int c) {
	if (r == 9) {
		return true;
	}
	bool ret = false;
	if (s[r][c] != '0') {
		ret=DFS(r + ((c + 1) / 9), (c + 1) % 9);
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (bit[0][r][i] ||bit[1][c][i] ||bit[2][(r / 3) * 3 + (c / 3)][i]) continue;
			bit[0][r][i] =true;
			bit[1][c][i]=true;
			bit[2][(r / 3) * 3 + (c / 3)][i]=true;
			s[r][c] = (i+1 + '0');
			ret=DFS(r + ((c + 1) / 9), (c + 1) % 9);
			if (ret) {
				break;
			}
			s[r][c] = '0';
			bit[0][r][i] = false;
			bit[1][c][i] = false;
			bit[2][(r / 3) * 3 + (c / 3)][i] = false;
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			bit[0][i][j] = false;
			bit[1][i][j] = false;
			bit[2][i][j] = false;
		}
	}
	for (int i = 0; i < 9; i++) {
		cin >> s[i];
		for (int j = 0; j < 9; j++) {
			if (s[i][j] != '0') {
				int t = s[i][j] - '0';
				bit[0][i][t-1] =true;
				bit[1][j][t-1]=true;
				bit[2][(i / 3) * 3 + (j / 3)][t-1] =true;
			}
		}
	}
	DFS(0, 0);
	for (int i = 0; i < 9; i++) {
		cout << s[i] << "\n";
	}

	return 0;
}