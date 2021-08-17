#include<iostream>
using namespace std;
int N, M,K,R,C,s[4][10][10];
bool visit[40][40];
bool Search(int n) {
	
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			int R2, C2;
			R2 = (n % 2 == 1) ? C:R;
			C2 = (n % 2 == 1) ? R : C;
			bool f = true;
			for (int i = 0; i < R2; i++) {
				for (int j = 0; j < C2; j++) {
					int nr = r + i;
					int nc = c + j;
					if (s[n][i][j] == 1 && (nr < 0 || nr >= N || nc < 0 || nc >= M || visit[nr][nc])) {
						f = false;
						break;
					}
				}
				if (!f) {
					break;
				}
			}
			if (f) {
				for (int i = 0; i < R2; i++) {
					for (int j = 0; j < C2; j++) {
						int nr = r + i;
						int nc = c + j;
						if (s[n][i][j] == 1) {
							visit[nr][nc] = true;
						}
					}
					
				}
				return true;
			}


		}
	}



	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = false;
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> R >> C;
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				cin >> s[0][j][k];
				s[1][k][R - 1 - j] = s[0][j][k];
				s[2][R - 1 - j][C - 1 - k] = s[0][j][k];
				s[3][C - 1 - k][j] = s[0][j][k];
				
			}
		}
		
		for (int j = 0; j < 4; j++) {
			if (Search(j)) {
				break;
			}
		}
		
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			answer += visit[i][j];
		}
		
	}
	cout << answer << "\n";
	return 0;
}