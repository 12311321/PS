#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
int N, M;
string s;
unordered_map<string, int> umap;
int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	umap.clear();
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s.size() >= 4) {
			sort(s.begin() + 1, s.end() - 1);
		}
		umap[s]++;
	}
	cin >> M;
	
	int answer;
	cin.ignore();
	for (int i = 0; i < M; i++) {
		
		getline(cin, s);
		answer = 1;
		string temp = "";
		for (int j = 0; j < s.size(); j++) {
			if (s[j] != ' ') {
				temp += s[j];
			}
			else {
				if (temp.size() >= 4) {
					sort(temp.begin() + 1, temp.end() - 1);
				}

				int m = umap[temp];
				if (m > 1) {
					answer *= m;
				}
				
				temp = "";
			}
			
		}
		if (temp.size() >= 4) {
			sort(temp.begin() + 1, temp.end() - 1);
		}
		
		int m = umap[temp];
		if (m > 1) {
			answer *=m;
		}
		cout << answer << "\n";
	}
	return 0;
}


/*
3
ababa
aabba
abcaa
2
ababa a a a b abbaa abcaa acabb acaba
ababa a a a a a a a



*/