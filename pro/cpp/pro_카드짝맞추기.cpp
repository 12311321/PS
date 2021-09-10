#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;
struct Info {
    int bit;//비트가 1 : 짝이 맞춰져 제거된 상태, 0 : 아직 짝이 맞춰지지 않은 상태
    int open;//현재 열려있는 조각의 번호
    int r;
    int c;
    Info(int bit, int open, int r, int c) {
        this->bit = bit;
        this->open = open;
        this->r = r;
        this->c = c;
    }
};
int dp[1 << 7][14][4][4], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int solution(vector<vector<int>> board, int r, int c) {
    cout << 64 * 14 * 4 * 4 << endl;
    int answer = 0;
    int answerbit = 0;
    bool visit[7];
    for (int i = 0; i < 7; i++) {
        visit[i] = false;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            if (board[i][j] != 0 && !visit[board[i][j]]) {
                answerbit |= (1 << (board[i][j]));
                visit[board[i][j]] = true;
                board[i][j] += 7;//7을 더해주는 이유는 %7연산 시 같은 값을 내기위함
            }
        }
    }
    for (int i = 0; i < (1 << 7); i++) {
        for (int j = 0; j < 14; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }

    dp[0][0][r][c] = 0;
    queue<Info> q;
    q.push(Info(0, 0, r, c));
    while (!q.empty()) {
        Info t = q.front();
        q.pop();

        if (t.bit == answerbit) {
            answer = dp[t.bit][t.open][t.r][t.c];
            break;
        }
        //1. 엔터 
        int num = dp[t.bit][t.open][t.r][t.c];
        int target = board[t.r][t.c];
        if (target > 0 && (t.bit & (1 << (target % 7))) == 0) {

            if (t.open == 0) {
                if (dp[t.bit][target][t.r][t.c] == -1) {
                    dp[t.bit][target][t.r][t.c] = num + 1;

                    q.push(Info(t.bit, target, t.r, t.c));
                }
            }
            else if (t.open != target && (t.open % 7) == (target % 7)) {
                int nbit = (t.bit | (1 << (target % 7)));
                if (dp[nbit][0][t.r][t.c] == -1) {
                    dp[nbit][0][t.r][t.c] = num + 1;

                    q.push(Info(nbit, 0, t.r, t.c));
                }
            }
        }
        //2. 사방으로 1칸
        for (int i = 0; i < 4; i++) {
            int nr = t.r + dx[i];
            int nc = t.c + dy[i];
            if (nr < 0 || nr>3 || nc < 0 || nc>3) continue;
            if (dp[t.bit][t.open][nr][nc] == -1) {
                dp[t.bit][t.open][nr][nc] = num + 1;

                q.push(Info(t.bit, t.open, nr, nc));
            }
        }
        //3. 사방으로 ctrl누르면서

        for (int i = 0; i < 4; i++) {
            int nr = t.r;
            int nc = t.c;
            while (1) {
                int nnr = nr + dx[i];
                int nnc = nc + dy[i];
                if (nnr < 0 || nnr>3 || nnc < 0 || nnc>3) break;
                int target2 = board[nnr][nnc];
                if (target2 > 0 && (t.bit & (1 << (target2 % 7))) == 0) {
                    nr = nnr;
                    nc = nnc;
                    break;
                }
                nr = nnr;
                nc = nnc;
            }
            if (dp[t.bit][t.open][nr][nc] == -1) {
                dp[t.bit][t.open][nr][nc] = num + 1;

                q.push(Info(t.bit, t.open, nr, nc));
            }
        }

    }

    return answer;
}