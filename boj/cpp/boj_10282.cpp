#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int T,n,d,c,a,b,s,answer_time,answer_num;
vector<pii> adjlist[10000];
bool visit[10000];
struct comp {
	bool operator()(pii p1, pii p2) {
		return p1.second > p2.second;
	}
};
priority_queue<pii, vector<pii>, comp> pq;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &d, &c);
		for (int i = 0; i < n; i++) {
			visit[i] = false;
		}
		for (int i = 0; i < d; i++) {
			scanf("%d%d%d", &a, &b, &s);
			adjlist[b - 1].push_back(pii(a - 1, s));
			
		}
		answer_time = 0;
		answer_num = 0;
		
		pq.push(pii(c - 1, 0));
		while (!pq.empty()) {
			pii t = pq.top();
			pq.pop();
			if (visit[t.first]) continue;
			visit[t.first] = true;
			answer_time = t.second;
			answer_num++;
			for (int i = 0; i < adjlist[t.first].size(); i++) {
				pii Edge = adjlist[t.first][i];
				if (!visit[Edge.first]) {
					pq.push(pii(Edge.first, Edge.second + t.second));
				}
			}

		}
		printf("%d %d\n", answer_num, answer_time);
		for (int i = 0; i < n; i++) {
			adjlist[i].clear();
		}

	}

	return 0;
}