#include<iostream>
#include<algorithm>
using namespace std;
int N, H,input[2][100000];
int main() {
	scanf("%d%d", &N, &H);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i % 2][i / 2]);
	}
	sort(input[0], input[0] + N/2);
	sort(input[1], input[1] + N/2);
	
	int answer = N,ct=0;
	int pos1 = 0;
	int pos2 = N/2-1;
	for (int i = 1; i <= H; i++) {
		while (pos1<N/2 && input[0][pos1] < i) {
			pos1++;
		}
		while (pos2 >= 0 && H - input[1][pos2] < i) {
			pos2--;
		}
		int s = N - pos1-pos2-1;
		
		if (answer > s) {
			ct = 1;
			answer = s;
		}
		else if (answer == s) {
			ct++;
		}
	}
	printf("%d %d\n", answer, ct);
	return 0;
}