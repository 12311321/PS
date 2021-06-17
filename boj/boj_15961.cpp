#include<iostream>
using namespace std;
int N, d, k, c,input[3000000],num[3001],ct;
int main() {
	scanf("%d%d%d%d", &N, &d, &k, &c);	
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);	
	}
	for (int i = 1; i <= d; i++) {
		num[i] = 0;
	}
	ct = 0;
	for (int i = 0; i < k; i++) {
		num[input[i]]++;
		if (num[input[i]] == 1) {
			ct++;
		}
	}
	int answer = 0;
	if (k == N) {
		if (num[c] == 0) {
			ct++;
		}
		answer = ct;
	}
	else {
		for (int i = 0; i < N; i++) {		
			if (num[c]==0) {
				answer = answer < (ct + 1) ? (ct + 1) : answer;
			}
			else {
				answer = answer < ct ? ct : answer;
			}
			num[input[i]]--;
			if (num[input[i]] == 0) {
				ct--;
			}
			num[input[(i + k) % N]]++;
			if (num[input[(i + k) % N]] == 1) {
				ct++;
			}
		}
		
		
	}
	printf("%d\n", answer);
	return 0;
}