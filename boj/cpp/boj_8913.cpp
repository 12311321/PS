#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
int T;
string s;
unordered_set<string> uset;
bool Search(string s) {
	uset.insert(s);
	if (s.size() == 0) {
		return true;
	}
	bool ret = false;
	int anum = (s[0] == 'a'), bnum = (s[0] == 'b');
	string nstr;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) {
			if (anum >= 2) {
				nstr = s.substr(0, i - anum) + s.substr(i);
				if (uset.count(nstr) == 0) {
					ret |= Search(nstr);
				}
			}
			else if (bnum >= 2) {
				nstr = s.substr(0, i - bnum) + s.substr(i);
				if (uset.count(nstr) == 0) {
					ret |= Search(nstr);
				}
			}
			anum = 0;
			bnum = 0;
		}
		anum += (s[i] == 'a');
		bnum += (s[i] == 'b');

	}
	if (anum >= 2) {
		nstr = s.substr(0, s.size() - anum);
		if (uset.count(nstr) == 0) {
			ret |= Search(nstr);
		}

	}
	else if (bnum >= 2) {
		nstr = s.substr(0, s.size() - bnum);
		if (uset.count(nstr) == 0) {
			ret |= Search(nstr);
		}
	}
	return ret;
}
int main() {

	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> s;
		uset.clear();
		cout << Search(s) << "\n";
	}
	return 0;
}