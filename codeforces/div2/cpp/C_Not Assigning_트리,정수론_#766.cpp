#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int t, n, u, v,con[4];
vector<pii> adjList[100000];
int ans[100000];
bool visit[100000];
queue<int> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			adjList[i].clear();
			visit[i] = false;
		}
		for (int i = 0; i < n-1; i++) {
			cin >> u >> v;
			adjList[u - 1].push_back(pii(v - 1,i));
			adjList[v - 1].push_back(pii(u - 1,i));
		}
		bool valid = true;
		for (int i = 0; i < n; i++) {
			if (adjList[i].size() >= 3) {
				valid = false;
				break;
			}
		}


		if (valid) {
			for (int i = 0; i < n; i++) {
				if (adjList[i].size() == 1) {
					visit[i] = true;
					q.push(i);
					bool flag = false;
					while (!q.empty()) {
						int p = q.front();
						q.pop();
						flag = !flag;

						for (int j = 0; j < adjList[p].size(); j++) {
							pii edge = adjList[p][j];
							if (visit[edge.first]) continue;
							if (flag) {
								ans[edge.second] = 2;
							}
							else {
								ans[edge.second] = 5;
							}
							visit[edge.first] = true;
							q.push(edge.first);
						}
					}
					break;
				}
			}
			for (int i = 0; i < n - 1; i++) {
				cout << ans[i] << " ";
			}
			cout << "\n";
		}
		else {
			cout << -1 << "\n";
		}

	}

	return 0;
}