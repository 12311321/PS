

#include<iostream>
using namespace std;
int N,A[20][20],acc[21][21],sum;
int retPop(int r, int c, int c2) {
	return acc[r][c2+1] - acc[r][c];
}
int Search(int x, int y,int d1, int d2) {
	int maxpop = -1;
	int minpop = (1 << 30);
	int pop[5] = { 0, };
	
	

	

	for (int i = 0; i < x + d1; i++) {
		if (i < x) {
			pop[0] += retPop(i, 0, y);
			
		}
		else {
			pop[0] += retPop(i, 0, y - i + x-1);
			
		}
	}
	
	for (int i = 0; i <= x + d2; i++) {
		if (i < x) {
			pop[1] += retPop(i, y+1, N-1);
			
		}
		else {
			pop[1] += retPop(i, y+1+i-x,N-1);
			
		}
	}
	
	for (int i = N-1; i >=x+d1; i--) {
		if (i>x+d1+d2) {
			pop[2] += retPop(i, 0, y-d1+d2-1);
			
		}
		else {
			pop[2] += retPop(i, 0,y-d1+d2-1+(i-x-d1-d2));
			
		}
	}
	
	for (int i = N-1; i > x + d2; i--) {
		if (i > x+d1+d2) {
			pop[3] += retPop(i, y-d1+d2, N-1);
			
		}
		else {
			pop[3] += retPop(i,y-d1+d2+1-(i-(x+d1+d2)) , N-1);
			
		}
	}
	

	pop[4] = sum - pop[0] - pop[1] - pop[2] - pop[3];
	for (int i = 0; i < 5; i++) {
		maxpop = maxpop < pop[i] ? pop[i] : maxpop;
		minpop = minpop > pop[i] ? pop[i] : minpop;
	}
	return maxpop - minpop;
}
bool CheckBoundary(int x, int y, int d1, int d2) {
	if (x + d1+d2 >= N) {
		return false;
	}
	if (y-d1<0 || y+d2>=N) {
		return false;
	}
	return true;
}
int main() {
	scanf("%d", &N);
	sum = 0;
	for (int i = 0; i < N; i++) {
		acc[i][0] = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
			sum += A[i][j];
			acc[i][j + 1] = acc[i][j] + A[i][j];
		}		
	}

	int answer = (1 << 30);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 1; k <= N; k++) {
				for (int l = 1; l <= N; l++) {
					if (CheckBoundary(i, j, k, l)) {
						int ret = Search(i, j, k, l);
						answer = answer > ret ? ret : answer;
					}
				}
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}