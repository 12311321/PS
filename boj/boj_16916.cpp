#include<iostream>
#include<string>
using namespace std;
string P,S;
int f[1000000];
int main() {
	ios::sync_with_stdio(false);
	cin >> S >> P;
	bool answer = false;
	if (S.size() >= P.size()) {
		f[0] = 0;
		int j = 0;
		for (int i = 1; i < P.size(); i++) {
			f[i] = 0;
			while (j > 0 && P[i] != P[j]) {
				j = f[j - 1];
			}
			if (P[i] == P[j]) {
				f[i] = ++j;
			}
		}

		j = 0;
		for (int i = 0; i < S.size(); i++) {
			while (j > 0 && S[i] != P[j]) {
				j = f[j - 1];
			}
			if (S[i] == P[j]) {
				j++;
			}
			if (j == P.size()) {
				answer = true;
				break;
			}
		}
	}
	cout << answer << "\n";

	return 0;
}