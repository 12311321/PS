#include<iostream>
using namespace std;
int N, D, K,bm[1000],a,b,comb[15];
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> D >> K;
	for (int i = 0; i < N; i++) {
		bm[i] = 0;
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			bm[i] |= (1 << (b-1));
		}
	}
	
	for (int i = 0; i < K; i++) {
		comb[i] = i;
	}
	int answer = 0;
	while (1) {
		int bt = 0;
		for (int i = 0; i < K; i++) {
			bt |= (1 << comb[i]);	
		}
		int ct = 0;
		for (int i = 0; i < N; i++) {
			if ((bt | bm[i]) == bt) {
				ct++;
			}
		}
		answer = answer < ct ? ct : answer;
		int pos = K - 1;
		while (pos>=0 && comb[pos] == D + pos - K) {
			pos--;
		}
		if (pos == -1) {
			break;
		}
		comb[pos]++;
		for (int i = pos + 1; i < K; i++) {
			comb[i] = comb[i - 1] + 1;
		}
	}
	cout << answer << "\n";
	return 0;
}