#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int N;
string s[10000];

bool CompStr(const string& s1, const string& s2);
bool CompAlp(const char& c1, const char& c2);
bool IsAlp(const char& c);
int CompStrNum(const string& s1, const string& s2);
int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[i];

	}
	sort(s, s + N, CompStr);
	for (int i = 0; i < N; i++) {
		cout << s[i] << "\n";
	}
	return 0;
}
bool CompStr(const string& s1, const string& s2) {

	int idx1 = 0, idx2 = 0;
	while (1) {
		if (idx1 == s1.size()) {
			return true;
		}
		else if (idx2 == s2.size()) {
			return false;
		}
		if (IsAlp(s1[idx1]) && IsAlp(s2[idx2])) {
			if (s1[idx1] != s2[idx2]) {
				return CompAlp(s1[idx1], s2[idx2]);
			}
			idx1++;
			idx2++;
		}
		else {
			if (!IsAlp(s1[idx1]) && !IsAlp(s2[idx2])) {
				string t1 = "", t2 = "";
				while (!IsAlp(s1[idx1]) && idx1 != s1.size()) {
					t1 += s1[idx1];
					idx1++;
				}

				while (!IsAlp(s2[idx2]) && idx2 != s2.size()) {
					t2 += s2[idx2];
					idx2++;
				}

				int r = CompStrNum(t1, t2);
				if (r == 1) {
					return true;
				}
				else if (r == -1) {
					return false;
				}

			}
			else {
				return IsAlp(s2[idx2]);
			}
		}

	}
}
bool CompAlp(const char& c1, const char& c2) {
	if (c1 >= 'A' && c1 <= 'Z' && c2 >= 'A' && c2 <= 'Z') {
		return c1 < c2;
	}
	else if (c1 >= 'a' && c1 <= 'z' && c2 >= 'a' && c2 <= 'z') {
		return c1 < c2;
	}
	else {
		if (c1 >= 'A' && c1 <= 'Z') {
			return c1 <= (c2 + ('A' - 'a'));
		}
		else {
			return c1 < (c2 + ('a' - 'A'));
		}
	}
}
bool IsAlp(const char& c) {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
int CompStrNum(const string& s1, const string& s2) {
	int idx1 = 0, idx2 = 0;
	while (s1[idx1] == '0' && idx1 < s1.size()) {
		idx1++;
	}
	while (s2[idx2] == '0' && idx2 < s2.size()) {
		idx2++;
	}
	if (s1.size() - idx1 < s2.size() - idx2) {
		return 1;
	}
	else if (s1.size() - idx1 > s2.size() - idx2) {
		return -1;
	}
	while (1) {
		if (idx1 == s1.size() && idx2 == s2.size()) {
			if (s1.size() == s2.size()) {
				return 0;
			}
			else if (s1.size() < s2.size()) {
				return 1;
			}
			else {
				return -1;
			}
		}
		if (s1[idx1] < s2[idx2]) {
			return 1;
		}
		else if (s1[idx1] > s2[idx2]) {
			return -1;
		}


		idx1++;
		idx2++;
	}


}
