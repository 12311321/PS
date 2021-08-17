#include<iostream>
#include<string>
using namespace std;
string s,localnum;
int N, month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
	ios::sync_with_stdio(false);
	cin >> s;
	cin >> N;
	string localcode;
	localcode = s.substr(0, 6);
	bool f = false;
	for (int i = 0; i < N; i++) {
		cin >> localnum;
		if (localnum == localcode) {
			f = true;
		}
	}
	if (f) {
		string birthcode = s.substr(6, 8);
		int y = 0;
		for (int i = 0; i < 4; i++) {
			y *= 10;
			y += (birthcode[i] - '0');
		}
		if (y < 1900 || y>2011) {
			f = false;
		}
		int m = 0;
		for (int i = 4; i < 6; i++) {
			m *= 10;
			m += (birthcode[i] - '0');
		}
		if (m < 1 || m>12) {
			f = false;
		}
		int d = 0;
		for (int i = 6; i < 8; i++) {
			d *= 10;
			d += (birthcode[i] - '0');
		}
		int lim = month[m - 1];
		if (m == 2 && y % 4 == 0 && y%100!=0) {
			lim++;
		}
		else if (y == 2000) {
			lim++;
		}
		if (d<1 || d>lim) {
			f = false;
		}
	}
	if (f) {
		int t = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			t += (s[i] - '0') * (1 << (17 - i));
			t %= 11;
		}
		if (s[s.size() - 1] == 'X') {
			t += 10;
		}
		else {
			t += (s[s.size() - 1] - '0');
		}
		t %= 11;
		if (t != 1) {
			f = false;
		}
	}
	if (!f) {
		cout << "I\n";
	}
	else {
		if (s[16] == '0' && s[15] == '0' && s[14] == '0') {
			cout << "I\n";
		}
		else if ((s[16] - '0') % 2 == 1) {
			cout << "M\n";
		}
		else {
			cout << "F\n";
		}
	}
	return 0;
}