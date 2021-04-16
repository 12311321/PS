#include <string>
#include <vector>
#include<unordered_map>
#include<string>
#include<queue>
#include<iostream>
using namespace std;
struct info {
    int t;
    int n;
    info(int t, int n) {
        this->t = t;
        this->n = n;
    }
};
struct comp {
    bool operator()(info i1, info i2) {
        return i1.t > i2.t;
    }
};
unordered_map<string, int> umap;
priority_queue<info, vector<info>, comp> pq;
int cache[100000];
int solution(int cacheSize, vector<string> cities) {
    int ct = 0;
    int answer = 0;
    int pq_sz = 0;
    for (int i = 0; i < cities.size(); i++) {
        cache[i] = -1;
        for (int j = 0; j < cities[i].size(); j++) {
            if (cities[i][j] >= 'a') {
                cities[i][j] -= ('a' - 'A');
            }
        }
    }
    for (int i = 0; i < cities.size(); i++) {
        if (umap.count(cities[i]) == 0) {
            umap[cities[i]] = ct++;
        }
        int country_num = umap[cities[i]];

        if (cacheSize == 0) {
            answer += 5;
        }
        else {
            if (pq_sz < cacheSize) {
                if (cache[country_num] == -1) {
                    pq_sz++;
                    answer += 4;
                }
                cache[country_num] = i;
                pq.push(info(i, country_num));
                answer += 1;
            }
            else {

                if (cache[country_num] == -1) {
                    while (pq.top().t != cache[pq.top().n]) {
                        pq.pop();
                    }
                    cache[pq.top().n] = -1;
                    pq.pop();
                    pq.push(info(i, country_num));
                    cache[country_num] = i;
                    answer += 5;
                }
                else {
                    pq.push(info(i, country_num));
                    cache[country_num] = i;
                    answer += 1;
                }
            }

        }
    }
    return answer;
}