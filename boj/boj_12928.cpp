#include<iostream>
#include<string>
using namespace std;
string s;
int N,indeg[100];
bool adj[100][100],visit[100];
void DFS(int k) {
	visit[k] = true;
	for (int i = 0; i < N; i++) {
		if (adj[k][i] && !adj[i][k]) {
			indeg[i]--;
			if (indeg[i] == 0) {
				DFS(i);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	bool f = true;
	for (int i = 0; i < N; i++) {
		cin >> s;
		indeg[i] = 0;
		if (s[i] == 'Y') {
			f = false;
		}
		
		for (int j = 0; j < N; j++) {
			adj[i][j] = (s[j] == 'Y');
		}
	}
	
	if (f) {
		for (int i = 0; i < N; i++) {
			visit[i] = false;
			for (int j = 0; j < N; j++) {
				if (adj[i][j] && !adj[j][i]) {
					indeg[j]++;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (!visit[i] && indeg[i] == 0) {
				DFS(i);
			}
		}
		for (int i = 0; i < N; i++) {
			if (indeg[i] != 0) {
				f = false;
				break;
			}
		}
	}
	
	cout << (f ? "YES" : "NO") << "\n";
	return 0;
}