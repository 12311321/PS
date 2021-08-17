#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<char, int> pci;
int N;
string s;
pci p1[100][5],*p2[500];
stack<pci*> st;
bool compare(const pci *a, const pci *b) {
	if (a->first < b->first) {
		return true;
	}
	else if (a->first > b->first) {
		return false;
	}
	else {
		return a->second < b->second;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> s;
			int t = 0;
			for (int i = 2; i < s.size(); i++) {
				t *= 10;
				t += s[i] - '0';
			}
			p1[i][j] = pci(s[0], t);
			p2[i * 5 + j] = &p1[i][j];
		}
	}
	sort(p2, p2 + 5 * N,compare);
	bool f = true;
	int pos=0;
	for (int i = 0; i < 5 * N; i++) {
		
		if (!st.empty() && st.top()==p2[i]) {
			
			st.pop();
		}
		else {
			while (pos < 5 * N && &p1[pos/5][pos%5]!=p2[i]) {
				
				st.push(&p1[pos / 5][pos % 5]);
				pos++;
			}
			if (pos >= 5 * N) {
				f = false;
				break;
			}
			
			pos++;
		}
	}
	cout << (f ? "GOOD" : "BAD") << "\n";
	return 0;
}