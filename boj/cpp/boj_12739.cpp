/*
RGB



*/
#include<iostream>
#include<string>
using namespace std;
string s;
int N, K,ncolor[3],color[1001][1000];
int main() {
	ios::sync_with_stdio(false);
	cin >>N>>K>>s;
	
	for (int i = 0; i < N; i++) {
		switch (s[i]) {
		case 'R':
			color[0][i] = 0;
			break;
		case 'G':
			color[0][i] = 1;
			break;
		case 'B':
			color[0][i] = 2;
			break;

		}
	}
	for (int i = 1; i <= K; i++) {
		ncolor[0] = 0;
		ncolor[1] = 0;
		ncolor[2] = 0;
		for (int k = -1; k <= 1; k++) {
			int idx = color[i - 1][(N + k) % N];
			ncolor[idx]++;
		}
		int j = 0;
		while (1) {
			if (ncolor[0] * ncolor[1] * ncolor[2] == 1 || ncolor[0] == 3 || ncolor[1] == 3 || ncolor[2] == 3) {
				color[i][j] = 2;
			}
			else if ((ncolor[0] == 2 && ncolor[1] == 1) || (ncolor[1] == 2 && ncolor[2] == 1) || (ncolor[2] == 2 && ncolor[0] == 1)) {
				color[i][j] = 0;
			}
			else {
				color[i][j] = 1;
			}

			if (j == N - 1) {
				break;
			}
			int idx = color[i - 1][(N + j - 1) % N];
			ncolor[idx]--;
			idx = color[i - 1][(j + 2) % N];
			ncolor[idx]++;
			j++;
			
			
		}
	}
	ncolor[0] = 0;
	ncolor[1] = 0;
	ncolor[2] = 0;
	for (int i = 0; i < N; i++) {
		ncolor[color[K][i]]++;
	}
	cout <<ncolor[0] << " " << ncolor[1] << " " << ncolor[2] << "\n";
	return 0;
}