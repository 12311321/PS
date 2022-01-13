#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct comp {
	bool operator()(const int& a, const int& b) {
		return a > b;
	}
};
struct Edge {
	int e, cnt;
	Edge() {
		e = 0;
		cnt = 0;
	}
	Edge(int e, int cnt) {
		this->e = e;
		this->cnt = cnt;
	}
};
int N, M, s, e, m, inDeg[100001];
vector<Edge> adjList[100001];
void reset(int k) {
	for (int i = 1; i <= N; i++) {
		inDeg[i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < adjList[i].size(); j++) {
			Edge* e = &adjList[i][j];
			if (e->cnt <= k) {
				inDeg[e->e]++;
			}
		}
	}
}
bool check(int k) {
	reset(k);
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDeg[i] == 0) {
			q.push(i);
		}
	}
	int visitCnt = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		visitCnt++;
		for (int i = 0; i < adjList[now].size(); i++) {
			Edge* e = &adjList[now][i];
			if (e->cnt > k) continue;
			inDeg[e->e]--;
			if (inDeg[e->e] == 0) {
				q.push(e->e);
			}
		}
	}

	return visitCnt == N;
}
void print(int k) {
	reset(k);
	priority_queue<int, vector<int>, comp> pq;
	for (int i = 1; i <= N; i++) {
		if (inDeg[i] == 0) {
			pq.push(i);
		}
	}
	
	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();	
		cout << now << " ";	
		for (int i = 0; i < adjList[now].size(); i++) {
			Edge* e = &adjList[now][i];
			if (e->cnt > k) continue;
			inDeg[e->e]--;
			if (inDeg[e->e] == 0) {
				pq.push(e->e);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		adjList[i].clear();
	}
	
	for (int i = 1; i <= M; i++) {
		cin >> m;
		cin >> s;
		for (int j = 1; j < m; j++) {
			cin >> e;
			adjList[s].push_back(Edge(e,i));
			s = e;
		}
	}

	s = 1; e = M;
	int k = 0;
	while (s <= e) {
		int m = (s + e) / 2;
		if (check(m)) {
			k = m;
			s = m + 1;
		}
		else {
			e = m - 1;
		}
	}
	print(k);
	return 0;
}