#include <string>
#include <vector>
#include<iostream>
#include<cstdlib>
using namespace std;
typedef long long ll;
vector<ll> v;
ll Search(int bit, vector<ll> v) {
    if (bit == 7) {
        return abs(v[0]);
    }
    ll ret = 0;
    if ((bit | (1 << 0)) != bit) {
        vector<ll> v2;
        int idx = 0;
        while (idx < v.size()) {
            if (idx % 2 == 1 && v[idx] == 0) {
                v2.back() += v[idx + 1];
                idx += 2;
            }
            else {
                v2.push_back(v[idx]);
                idx++;
            }
        }


        ll r = Search((bit | (1 << 0)), v2);
        ret = ret < r ? r : ret;
    }
    if ((bit | (1 << 1)) != bit) {
        vector<ll> v2;
        int idx = 0;
        while (idx < v.size()) {
            if (idx % 2 == 1 && v[idx] == 1) {
                v2.back() -= v[idx + 1];
                idx += 2;
            }
            else {
                v2.push_back(v[idx]);
                idx++;
            }
        }
        ll r = Search((bit | (1 << 1)), v2);
        ret = ret < r ? r : ret;
    }
    if ((bit | (1 << 2)) != bit) {
        vector<ll> v2;
        int idx = 0;
        while (idx < v.size()) {
            if (idx % 2 == 1 && v[idx] == 2) {
                v2.back() *= v[idx + 1];
                idx += 2;
            }
            else {
                v2.push_back(v[idx]);
                idx++;
            }
        }


        ll r = Search((bit | (1 << 2)), v2);
        ret = ret < r ? r : ret;
    }
    return ret;
}
long long solution(string expression) {
    long long answer = 0;

    v.push_back(0);
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            v.back() *= 10;
            v.back() += (expression[i] - '0');
        }
        else {
            switch (expression[i]) {
            case '+':
                v.push_back(0);
                break;
            case '-':
                v.push_back(1);
                break;
            case '*':
                v.push_back(2);
                break;
            }
            v.push_back(0);
        }
    }

    answer = Search(0, v);

    return answer;
}