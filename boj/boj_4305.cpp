#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
vector<int> adjlist[26];
int N,ct,sccn,scc[26],visit[26];
char c[6];
stack<int> st;
int DFS(int k) {
	visit[k] = ct;
	int ret = ct;
	ct++;
	st.push(k);
	for (int i = 0; i < adjlist[k].size(); i++) {
		int next = adjlist[k][i];
		if (visit[next]==-1) {
			int r=DFS(next);
			ret = r < ret ? r : ret;
		}
		else if (scc[next] == -1 && visit[next]!=-1) {
			ret = ret > visit[next] ? visit[next] : ret;
		}
	}
	if (ret == visit[k]) {
		while (st.top() != k) {
			scc[st.top()] = sccn;
			st.pop();
		}
		scc[st.top()] = sccn;
		st.pop();
		sccn++;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	while (N != 0) {
		sccn = 0;
		for (int i = 0; i < 26; i++) {
			adjlist[i].clear();
			visit[i] = -2;
			scc[i] = -1;
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 6; j++) {
				cin >> c[j];
			}
			for (int j = 0; j < 5; j++) {
				visit[c[j] - 'A'] = -1;
				adjlist[c[j] - 'A'].push_back(c[5] - 'A');
			}
		}
		
		for (int i = 0; i < 26; i++) {
			if (visit[i]==-1) {
				ct = 0;
				DFS(i);
			}
		}
		vector<int> answer[26];
		bool check[26];
		for (int i = 0; i < 26; i++) {
			check[i] = false;
			if (scc[i] >= 0) {

				answer[scc[i]].push_back(i);
			}
		}
		for (int i = 0; i < 26; i++) {
			if (scc[i]>=0 && !check[scc[i]]) {
				
				check[scc[i]] = true;
				for (int j = 0; j < answer[scc[i]].size(); j++) {
					cout << (char)(answer[scc[i]][j]+'A') << " ";
				}
				cout << "\n";
			}
		}
		cout << "\n";
		
		cin >> N;
	}
	return 0;
}