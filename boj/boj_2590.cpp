/*
1 1 1 0 0 0
1 1 1 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0





*/
#include<iostream>
using namespace std;
int input[6],answer;
int main() {
	for (int i = 0; i < 6; i++) {
		scanf("%d", &input[i]);
	}
	answer = input[5]+input[4]+input[3];
	
	input[0] -= input[4] * 11;
	input[1] -= input[3] * 5;
	if (input[1] < 0) {
		input[0] += 4 * input[1];	
	}
	answer += input[2] / 4;
	input[2] %= 4;
	if (input[2] > 0) {
		answer++;
		if (input[1] > 0) {
			input[1] -= 7 - (2 * input[2]);
			input[0] -= 8 - input[2];
			if (input[1] < 0) {
				input[0] += 4 * input[1];
			}
		}
		else if (input[0] > 0) {
			input[0] -= 36 - 9 * input[2];
		}
		
	}
	if (input[1] > 0) {
		answer += input[1] / 9;
		input[1] %= 9;
		if (input[1] > 0) {
			answer++;
			input[0] -= (36 - input[1] * 4);
		}
	}
	if (input[0] > 0) {
		answer += input[0] / 36 + (input[0] % 36 != 0);
	}
	
	printf("%d\n", answer);
	return 0;
}