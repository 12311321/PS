#include<iostream>
#include<algorithm>
using namespace std;
int N, M,u[500][500],f[500],r[500],answer[500][500];
int main() {
	scanf("%d%d", &N, &M);
	for (int i = N-1; i >=0; i--) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &u[i][j]);
		}
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &f[i]);
		
		
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &r[i]);
		
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (u[i][j] == 0) {
				answer[i][j] = 0;
			}
			else {
				answer[i][j] = min(f[j], r[i]);
			}
		}
	}
	bool a = true;
	for (int i = 0; i < M; i++) {
		int m = 0;
		for (int j = 0; j < N; j++) {
			m = max(answer[j][i],m);
		}
		
		if (m!=f[i]) {
			a = false;
			break;
		}
	}
	if (a) {
		for (int i = 0; i < N; i++) {
			int m = 0;
			for (int j = 0; j < M; j++) {
				m = max(answer[i][j], m);
			}
			if (m != r[i]) {
				a = false;
				break;
			}
		}

	}
	if (!a) {
		printf("-1\n");
	}
	else {
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				printf("%d ", answer[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}