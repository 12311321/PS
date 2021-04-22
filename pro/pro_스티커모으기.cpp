#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int dp[2][100000];
int solution(vector<int> sticker)
{
    int answer = 0;
    if (sticker.size() == 1) {
        answer = sticker[0];
    }
    else {
        dp[0][0] = 0;
        dp[1][0] = sticker[0];
        dp[0][1] = dp[1][0];
        dp[1][1] = sticker[1];
        for (int i = 2; i < sticker.size() - 1; i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
            dp[1][i] = max(dp[0][i - 1], dp[1][i - 2]) + sticker[i];
        }
        answer = max(answer, dp[0][sticker.size() - 2]);
        answer = max(answer, dp[1][sticker.size() - 2]);
        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[0][1] = 0;
        dp[1][1] = sticker[1];
        for (int i = 2; i < sticker.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
            dp[1][i] = max(dp[0][i - 1], dp[1][i - 2]) + sticker[i];
        }
        answer = max(answer, dp[0][sticker.size() - 1]);
        answer = max(answer, dp[1][sticker.size() - 1]);

    }
    return answer;
}