#include<iostream>
#include<string>
using namespace std;
int t,n;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n>>s;
		if (s.size() == 2) {
			if (s == "00" || s == "11") {
				cout << "NO\n";
			}
			else {
				cout << "YES\n";
			}
		}
		else if (s.size() == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}