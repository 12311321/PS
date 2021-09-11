#include <vector>
#include<iostream>
using namespace std;
const int INF = 101;
int dp[101][201];
vector<int> adjlist[201];
// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = INF;
    for (int i = 1; i <= n; i++) {
        adjlist[i].clear();
    }//���� �ʱ�ȭ

    for (int i = 0; i < m; i++) {
        int a = edge_list[i][0];
        int b = edge_list[i][1];
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }//��������Ʈ

    for (int i = 1; i <= n; i++) {
        adjlist[i].push_back(i);
    }//�� ������ �ӹ����� ���
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
    dp[1][gps_log[0]] = 0;


    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 0; l < adjlist[j].size(); l++) {
                int next = adjlist[j][l];
                int ncost = dp[i - 1][j] + (gps_log[i - 1] != next);
                dp[i][next] = dp[i][next] > ncost ? ncost : dp[i][next];

            }
        }
    }

    if (dp[k][gps_log[k - 1]] == INF) {
        answer = -1;
    }
    else {
        answer = dp[k][gps_log[k - 1]];
    }

    return answer;
}