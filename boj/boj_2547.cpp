#include<iostream>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
struct Flower {
	pii s;
	pii e;
	Flower(int sm, int sd, int em, int ed) {
		s.first = sm;
		s.second = sd;
		e.first = em;
		e.second = ed;
	}
};
int CompareDate(pii p1, pii p2) {
	if (p1.first > p2.first) {
		return 1;
	}
	else if (p1.first < p2.first) {
		return -1;
	}
	else {
		if (p1.second > p2.second) {
			return 1;
		}
		else if (p1.second < p2.second) {
			return -1;
		}
		else {
			return 0;
		}
	}
}
struct compare1 {
	bool operator()(Flower f1, Flower f2) {
		if (CompareDate(f1.s, f2.s)>0) {
			return true;
		}
		else {
			return false;
		}
	}
};
struct compare2 {
	bool operator()(Flower f1, Flower f2) {
		if (CompareDate(f1.e, f2.e) < 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

int N,a,b,c,d;
priority_queue<Flower, vector<Flower>, compare1> pq1;
priority_queue<Flower, vector<Flower>, compare2> pq2;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		pq1.push(Flower(Flower(a, b, c, d)));
	}
	int answer = 0;
	pii date(3, 1);
	while (1) {
		if (date.first >= 12 || pq1.empty()) {
			break;
		}
		while (!pq1.empty() && CompareDate(date, pq1.top().s) >= 0) {
			pq2.push(pq1.top());
			pq1.pop();
		}
		if (pq2.empty() || CompareDate(date, pq2.top().e) >= 0) {
			break;
		}
		date = pq2.top().e;
		pq2.pop();
		answer++;
	}
	if (date.first < 12) {
		answer = 0;
	}
	printf("%d\n", answer);
	return 0;
}