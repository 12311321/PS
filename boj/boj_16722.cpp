#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
bool f[9][9][9];
int habnum,k,input[9][3],x,y,z;
char c[3][3] = { {'C','S','T'},{'Y','R','B'},{'G','B','W'} };
bool isHab(int a, int b, int c) {
	for (int i = 0; i < 3; i++) {
		
		if (!((input[a][i] == input[b][i] && input[b][i]==input[c][i]) || (input[a][i]!=input[b][i] && input[a][i]!=input[c][i] && input[b][i]!=input[c][i]))) {
			return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				f[i][j][k] = false;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> s;
			for (int k = 0; k < 3; k++) {
				if (s[0] == c[j][k]) {
					input[i][j] = k;
					break;
				}
				
			}
			
			
		}		
	}
	habnum = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			for (int k = j + 1; k < 9; k++) {
				if (isHab(i,j,k)) {
					f[i][j][k] = true;
					habnum++;
					
				}
				
			}
		}
	}
	


	int score = 0;
	cin >> k;
	bool gscore = false;
	for (int i = 0; i < k; i++) {
		cin >> s;
		if (s=="G") {
			if (habnum == 0 && !gscore) {
				score += 3;
				gscore = true;
			}
			else {
				score -= 1;
			}
		}
		else {
			cin >> x >> y >> z;
			int nx = min(x, min(y, z));
			int nz = max(x, max(y, z));
			int ny = x + y + z - nx - nz;
		
			if (f[nx-1][ny-1][nz-1]) {
				score++;
				f[nx-1][ny-1][nz-1] = false;
				habnum--;
			}
			else {
				score--;
			}
		}
	}
	cout << score << "\n";
	return 0;
}