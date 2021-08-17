#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int N;
string s[1000];

bool comp(string s1, string s2) {
	int idx1 = 0, idx2 = 0;
	while (1) {
		if (idx2 == s2.size() || (idx1==s1.size() && idx2==s2.size())) {
			return false;
		}
		if (idx1 == s1.size()) {
			return true;
		}
		int a, b;
		if (s1[idx1] == 'n' && idx1+1<s1.size() && s1[idx1+1]=='g') {
			a = 'o';
			idx1 += 2;
		}
		else{
			a = s1[idx1] + (s1[idx1] >= 'o');
			idx1++;
		}
		if (s2[idx2] == 'n' && idx2+1<s2.size() && s2[idx2+1]=='g') {
			b = 'o';
			idx2 += 2;
		}
		else {
			b = s2[idx2] + (s2[idx2] >= 'o');
			idx2++;
		}
		if (a > b) {
			return false;
		}
		else if (a < b) {
			return true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++) {
			if (s[i][j] == 'k') {
				s[i][j] = 'c';
			}
		}
	}
	sort(s, s + N, comp);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < s[i].size(); j++) {
			if (s[i][j] == 'c') {
				s[i][j] = 'k';
			}
		}
		cout << s[i] << "\n";
	}
	return 0;
}