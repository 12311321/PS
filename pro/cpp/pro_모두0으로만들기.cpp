#include <string>
#include <vector>
#include<iostream>
using namespace std;
typedef long long ll;
vector<int> adjlist[300000];
ll w[300000], ct;
bool visit[300000];
ll Abs(ll k) {
    return k < 0 ? -k : k;
}
void DFS(int k) {
    visit[k] = true;
    for (int i = 0; i < adjlist[k].size(); i++) {
        int next = adjlist[k][i];
        if (!visit[next]) {
            DFS(next);
            ct += Abs(w[next]);
            w[k] += w[next];
        }
    }
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = -1;
    for (int i = 0; i < a.size(); i++) {
        adjlist[i].clear();
        w[i] = a[i];
        visit[i] = false;
    }
    for (int i = 0; i < edges.size(); i++) {
        int s = edges[i][0];
        int e = edges[i][1];
        adjlist[s].push_back(e);
        adjlist[e].push_back(s);
    }
    ct = 0;
    DFS(0);
    if (w[0] == 0) {
        answer = ct;
    }
    return answer;
}