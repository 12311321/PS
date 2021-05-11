#include<iostream>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, M,board[2][20][20],visit[20][20],ct,score,ct2;
pii d[4] = { pii(1,0),pii(0,1),pii(-1,0),pii(0,-1) };
struct Info {
	pii pos[400];
	int sz;
	int rainbow;
	int r;
	int c;
};
void Gravity(int (&board)[20][20]) {
	for (int i = 0; i < N; i++) {
		int pos = N-1;
		for (int j = N-1; j >=0; j--) {
			if (board[j][i] == -1) {
				pos = j-1;
			}
			else if (board[j][i] != -2) {
				int t = board[j][i];
				board[j][i] = -2;
				board[pos--][i] = t;
				
			}
		}
	}
}
bool Play() {
	queue<pii> q;
	Info save,temp;
	save.sz = 0;
	save.rainbow = 0;
	save.r = -1;
	save.c = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] != ct2 && board[ct%2][i][j]>0) {
				int color = board[ct % 2][i][j];
				visit[i][j] = ct2;
				temp.r = i;
				temp.c = j;
				temp.rainbow = 0;
				temp.sz = 0;
				q.push(pii(i, j));
				while (!q.empty()) {
					pii t = q.front();			
					q.pop();

					temp.pos[temp.sz++] = t;
					temp.rainbow += (board[ct % 2][t.first][t.second] == 0);
					if (board[ct % 2][t.first][t.second] != 0) {
						if (temp.r > t.first) {
							temp.r = t.first;
							temp.c = t.second;
						}
						else if (temp.r == t.first) {
							temp.c = temp.c > t.second ? t.second : temp.c;
						}
					}
					for (int k = 0; k < 4; k++) {
						int nr = t.first + d[k].first;
						int nc = t.second + d[k].second;
						if (nr < 0 || nr >= N || nc < 0 || nc >= N || visit[nr][nc]==ct2 || board[ct%2][nr][nc]<=-1) continue;
						if (board[ct % 2][nr][nc] != 0 && board[ct % 2][nr][nc] != color) continue;
						visit[nr][nc] = ct2;
						q.push(pii(nr, nc));
						
					}
				}
				ct2++;
				
				if (temp.sz > save.sz) {
					save = temp;
				}
				else if (temp.sz == save.sz) {
					if (temp.rainbow > save.rainbow) {
						save = temp;
					}
					else if (temp.rainbow == save.rainbow) {
						if (temp.r > save.r) {
							save = temp;
						}
						else if (temp.r == save.r && temp.c > save.c) {
							save = temp;
						}
					}
				}

			}
		}
	}
	if (save.sz < 2) {
		return false;
	}
	
	score += (save.sz) * (save.sz);
	for (int i = 0; i < save.sz; i++) {
		board[ct % 2][save.pos[i].first][save.pos[i].second] = -2;
	}
	
	
	Gravity(board[ct % 2]);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[1 - (ct % 2)][N - 1 - j][i] = board[ct % 2][i][j];
		}
	}
	
	
	Gravity(board[1 - (ct % 2)]);
	
	return true;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[0][i][j]);
			visit[i][j] = -1;
		}
	}
	score = 0;
	ct = 0;
	ct2 = 0;
	while (Play()) {
		ct++;
	}
	printf("%d\n", score);
	return 0;
}

