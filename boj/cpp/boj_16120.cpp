#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s;
stack<char> st;
int main() {
	ios::sync_with_stdio(false);
	cin >> s;
	int idx = 0;
	while(idx<s.size()){
		if (s[idx] == 'P') {
			st.push('P');
		}
		else {
			if (st.size() >= 2 && idx<s.size()-1 && s[idx+1]=='P') {
				st.pop();
				idx += 2;
				continue;
			}
			else {
				break;
			}
		}
		idx++;
	}
	if (idx==s.size() && st.size() == 1) {
		cout << "PPAP\n";
	}
	else {
		cout << "NP\n";
	}
	return 0;
}