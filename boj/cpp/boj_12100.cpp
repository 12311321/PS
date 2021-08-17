#include<iostream>
using namespace std;
int N,board[20][20],answer;
void Search(int k, int board[20][20]) {
	
	
	if (k == 5) {
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				answer = answer < board[i][j] ? board[i][j] : answer;

			}
		}
	}
	else {
		for (int d = 0; d < 4; d++) {
			int nboard[20][20];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					nboard[i][j] = 0;
				}
			}
			switch (d) {
			case 0:
				
				for (int i = 0; i < N; i++) {
					int pos = 0;
					for (int j = 0; j <N; j++) {
						if (board[i][j] !=0) {
							if (nboard[i][pos] == 0) {
								nboard[i][pos] = board[i][j];
							}
							else if (nboard[i][pos] == board[i][j]) {
								nboard[i][pos++] *= 2;
								
							}
							else {
								nboard[i][++pos] = board[i][j];
							}
						}
					}
				}

				break;
			case 1:
				for (int i = 0; i < N; i++) {
					int pos = N-1;
					for (int j = N-1; j >=0; j--) {
						if (board[i][j] != 0) {
							if (nboard[i][pos] == 0) {
								nboard[i][pos] = board[i][j];
							}
							else if (nboard[i][pos] == board[i][j]) {
								nboard[i][pos--] *= 2;

							}
							else {
								nboard[i][--pos] = board[i][j];
							}
						}
					}
				}
				break;
			case 2:
				for (int i = 0; i < N; i++) {
					int pos = 0;
					for (int j = 0; j < N; j++) {
						if (board[j][i] != 0) {
							if (nboard[pos][i] == 0) {
								nboard[pos][i] = board[j][i];
							}
							else if (nboard[pos][i] == board[j][i]) {
								nboard[pos++][i] *= 2;

							}
							else {
								nboard[++pos][i] = board[j][i];
							}
						}
					}
				}
				break; 
			case 3:
				for (int i = 0; i < N; i++) {
					int pos = N-1;
					for (int j = N-1; j >=0; j--) {
						if (board[j][i] != 0) {
							if (nboard[pos][i] == 0) {
								nboard[pos][i] = board[j][i];
							}
							else if (nboard[pos][i] == board[j][i]) {
								nboard[pos--][i] *= 2;

							}
							else {
								nboard[--pos][i] = board[j][i];
							}
						}
					}
				}
				break;
			}
		
			Search(k + 1, nboard);
		}
	}

}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	answer = 0;
	Search(0, board);
	printf("%d\n", answer);
	return 0;
}