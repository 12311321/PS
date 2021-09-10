#include <iostream>
#include <vector>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
const int INF = 500001;
vector<pii> adjlist[50];
int dist[50];
struct compare {
    bool operator()(pii p1, pii p2) {
        return p1.second > p2.second;
    }
};

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for (int i = 0; i < N; i++) {
        adjlist[i].clear();
        dist[i] = INF;
    }
    for (int i = 0; i < road.size(); i++) {
        adjlist[road[i][0] - 1].push_back(pii(road[i][1] - 1, road[i][2]));
        adjlist[road[i][1] - 1].push_back(pii(road[i][0] - 1, road[i][2]));
    }
    priority_queue<pii, vector<pii>, compare> pq;
    pq.push(pii(0, 0));
    dist[0] = 0;
    while (!pq.empty()) {
        pii t = pq.top();
        pq.pop();
        if (t.second > dist[t.first]) continue;
        for (int i = 0; i < adjlist[t.first].size(); i++) {
            pii Edge = adjlist[t.first][i];
            int ndist = t.second + Edge.second;
            if (ndist < dist[Edge.first]) {
                dist[Edge.first] = ndist;
                pq.push(pii(Edge.first, ndist));
            }
        }

    }
    for (int i = 0; i < N; i++) {
        if (dist[i] <= K) {
            answer++;
        }
    }
    return answer;
}