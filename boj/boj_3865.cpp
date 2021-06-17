#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int N,ct,leafnum;
string s;
unordered_map<string, int> umap;
vector<int> adjlist[1200];
bool visit[1200];
void Init();
void DFS(int k);
int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	while (N != 0) {
		Init();
		for (int i = 0; i < N; i++) {
			cin >> s;
			string temp = s.substr(0, s.find(':'));
			
			if (umap.count(temp) == 0) {
				umap[temp] = ct++;
			}
			int pidx = umap[temp];
			temp = "";
			for (int j = s.find(':') + 1; j < s.size(); j++) {
				if (s[j] == ',' || s[j]=='.') {
					if (umap.count(temp) == 0) {
						umap[temp] = ct++;
					}
					int cidx = umap[temp];
					adjlist[pidx].push_back(cidx);
					temp = "";
				}
				else {
					temp += s[j];
				}
			}
		}
		DFS(0);
		cout <<leafnum << "\n";

		cin >> N;
	}
	return 0;
}
void Init() {
	umap.clear();
	ct = 0;
	leafnum = 0;
	for (int i = 0; i < N * 11; i++) {
		adjlist[i].clear();
		visit[i] = false;
	}
}
void DFS(int k) {
	int ret = 0;
	visit[k] = true;
	if (adjlist[k].size() == 0) {
		leafnum++;
		return;
	}
	for (int i = 0; i < adjlist[k].size(); i++) {
		int next = adjlist[k][i];
		if (!visit[next]) {
			DFS(next);
		}
	}
}