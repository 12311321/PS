/*
 max(s0 s1 s2 s3 s4 ... sN)= K 
 O(K*S.size)
 K1+K2+K3+... = P.size
 O(P.size * S.size)
 


 



*/


#include<iostream>
#include<string>
using namespace std;
string S, P;
int main() {
	ios::sync_with_stdio(false);
	cin >> S >> P;
	int answer = 0;
	int idx1 = 0;
	int ct = 0;
	while (idx1 < P.size()) {
		int max_len = 0;
		int n_len;
		for (int i = 0; i < S.size(); i++) {
			n_len = 0;
			for (int j = i; j < S.size(); j++) {
				if (P[idx1 + n_len] != S[j]) {
					break;
				}
				n_len++;
			}
			max_len = max_len < n_len ? n_len : max_len;
		}
		idx1 += max_len;
		ct++;
	}
	cout << ct << "\n";
	
	return 0;
}