#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        int max_len = 1;
        int n = 1;
        while (i + n < s.size() && i - n >= 0 && s[i + n] == s[i - n]) {
            max_len += 2;
            n++;
        }
        answer = max_len > answer ? max_len : answer;
        if (i < s.size() - 1 && s[i] == s[i + 1]) {
            max_len = 2;
            n = 1;
            while (i + n + 1 < s.size() && i - n >= 0 && s[i + n + 1] == s[i - n]) {
                max_len += 2;
                n++;
            }
            answer = max_len > answer ? max_len : answer;
        }

    }

    return answer;
}