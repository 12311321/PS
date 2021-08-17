#include<iostream>
#include<queue>
using namespace std;
struct Info {
	int D;
	int H;
	int line;
	int s;
};
struct compare {
	bool operator()(Info* i1, Info* i2) {
		if (i1->D < i2->D) {
			return true;
		}
		else if (i1->D > i2->D) {
			return false;
		}
		else {
			if (i1->H < i2->H) {
				return true;
			}
			else if (i1->H > i2->H) {
				return false;
			}
			else {
				return i1->line > i2->line;
			}
		}
	}
};
priority_queue<Info*, vector<Info*>, compare> pq;
int N, M, K;
Info people[100000];

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &people[i].D, &people[i].H);
		people[i].line = i % M;
		people[i].s = i / M;
	}
	for (int i = 0; i < M; i++) {
		pq.push(&people[i]);
	}
	int answer = 0;
	while (1) {
		Info *t = pq.top();
		if (t->line == (K % M) && t->s == (K / M)) {
			break;
		}
		pq.pop();
		answer++;
		if (t->line+(t->s+1)*M < N) {
			pq.push(&people[t->line + (t->s+1) * M]);
		}
		
		
	}
	printf("%d\n", answer);
	return 0;
}