#include<iostream>
#include<string>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
int R, C,bn;
string s[15],s2;
pii dir[4] = { pii(-1,0),pii(1,0),pii(0,-1),pii(0,1) },pos;
void Move(char c) {
	if (bn == 0) {
		return;
	}
	int dn;
	switch (c) {
	case 'U':
		dn = 0;
		break;
	case 'D':
		dn = 1;
		break;
	case 'L':
		dn = 2;
		break;
	case 'R':
		dn = 3;
		break;
	}
	
	int nr = pos.first + dir[dn].first;
	int nc = pos.second + dir[dn].second;
	if (s[nr][nc] == '.' || s[nr][nc]=='+') {
		if (s[pos.first][pos.second] == 'W') {
			s[pos.first][pos.second] = '+';
		}
		else {
			s[pos.first][pos.second] = '.';
		}
		pos.first = nr;
		pos.second = nc;
		if (s[nr][nc] == '+') {
			s[nr][nc] = 'W';
		}
		else {
			s[nr][nc] = 'w';
		}
		
	}
	else if (s[nr][nc] == 'b' || s[nr][nc] == 'B') {
		int nnr = nr + dir[dn].first;
		int nnc = nc + dir[dn].second;
		if (s[nnr][nnc] == '.' || s[nnr][nnc] == '+') {
			if (s[nnr][nnc] == '+') {
				s[nnr][nnc] = 'B';
				bn--;
			}
			else {
				s[nnr][nnc] = 'b';
			}
			if (s[nr][nc] == 'B') {
				s[nr][nc] = 'W';
				bn++;
			}
			else {
				s[nr][nc] = 'w';
			}
			if (s[pos.first][pos.second] == 'W') {
				s[pos.first][pos.second] = '+';
			}
			else {
				s[pos.first][pos.second] = '.';
			}
			pos.first = nr;
			pos.second = nc;


		}
		else {
			return;
		}


	}

}
int main() {
	ios::sync_with_stdio(false);
	cin >> R >> C;
	int tc = 1;
	while (R != 0) {
		bn = 0;
		for (int i = 0; i < R; i++) {
			cin >> s[i];
			for (int j = 0; j < s[i].size(); j++) {
				if (s[i][j] == 'w' || s[i][j] == 'W') {
					pos = pii(i, j);
				}
				else if (s[i][j] == 'b') {
					bn++;
				}
			}
		}
		cin >> s2;
		for (int i = 0; i < s2.size(); i++) {
			Move(s2[i]);
		}
		cout << "Game " << tc << ": " << (bn == 0 ? "complete" : "incomplete") << "\n";
		for (int i = 0; i < R; i++) {
			cout << s[i] << "\n";
		}
		tc++;
		cin >> R >> C;
	}
	return 0;
}