#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<string, int> psi;
int bmask[20];
vector<psi> temp[10];
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++) {
        bmask[i] = 0;
        for (int j = 0; j < orders[i].size(); j++) {
            bmask[i] |= (1 << (orders[i][j] - 'A'));
        }
    }
    int comb[10];
    for (int i = 0; i < course.size(); i++) {
        for (int j = 0; j < course[i]; j++) {
            comb[j] = j;
        }
        while (1) {
            int nbit = 0;
            string st = "";
            for (int j = 0; j < course[i]; j++) {
                nbit |= (1 << comb[j]);
                st += (comb[j] + 'A');
            }

            int ct = 0;
            for (int j = 0; j < orders.size(); j++) {
                if ((nbit & bmask[j]) == nbit) {
                    ct++;
                }
            }
            if (ct > 1) {
                if (temp[course[i] - 1].size() == 0) {
                    temp[course[i] - 1].push_back(psi(st, ct));
                }
                else {
                    if (temp[course[i] - 1][0].second == ct) {
                        temp[course[i] - 1].push_back(psi(st, ct));
                    }
                    else if (temp[course[i] - 1][0].second < ct) {
                        temp[course[i] - 1].clear();
                        temp[course[i] - 1].push_back(psi(st, ct));
                    }
                }
            }
            int pos = course[i] - 1;
            while (pos >= 0 && comb[pos] == 26 + pos - course[i]) {
                pos--;
            }
            if (pos == -1) {
                break;
            }
            comb[pos]++;
            for (int j = pos + 1; j < course[i]; j++) {
                comb[j] = comb[j - 1] + 1;
            }
        }
    }
    for (int i = 0; i < course.size(); i++) {
        for (int j = 0; j < temp[course[i] - 1].size(); j++) {
            answer.push_back(temp[course[i] - 1][j].first);

        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}