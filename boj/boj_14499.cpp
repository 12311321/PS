/*
   1
 3 0 2
   4
   5

*/


#include<iostream>
using namespace std;
int N, M, x, y, K, z, map[20][20], dice[6], dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };
void Move(int d) {
	int temp[6];
	for (int i = 0; i < 6; i++) {
		temp[i] = dice[i];
	}

	switch (d) {
	case 1:
		dice[5] = temp[2];
		dice[2] = temp[0];
		dice[0] = temp[3];
		dice[3] = temp[5];
		break;
	case 2:
		dice[5] = temp[3];
		dice[3] = temp[0];
		dice[0] = temp[2];
		dice[2] = temp[5];
		break;
	case 3:
		dice[5] = temp[1];
		dice[1] = temp[0];
		dice[0] = temp[4];
		dice[4] = temp[5];
		break;
	case 4:
		dice[1] = temp[5];
		dice[5] = temp[4];
		dice[4] = temp[0];
		dice[0] = temp[1];
		break;
	}
}
int main() {
	scanf("%d%d%d%d%d", &N, &M,&y,&x,&K);
	for (int i = 0; i < 6; i++) {
		dice[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < K; i++) {
		scanf("%d", &z);
		int ny = y + dy[z - 1];
		int nx = x + dx[z - 1];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
			Move(z);
			x = nx;
			y = ny;
			if (map[y][x] == 0) {
				map[y][x] = dice[5];
			}
			else {
				dice[5] = map[y][x];
				map[y][x] = 0;
			}
			printf("%d\n", dice[0]);
		}
	}
	return 0;
}