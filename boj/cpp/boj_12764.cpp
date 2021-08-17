#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct Info {
	int s;
	int e;
	int n;
	Info() {};
	Info(int s, int e, int n) {
		this->s = s;
		this->e = e;
		this->n = n;
	}
};
struct CompEndTime {
	bool operator()(Info i1, Info i2) {
		return i1.e > i2.e;
	}
};
struct CompNum {
	bool operator()(int a, int b) {
		return a > b;
	}
};
bool CompStartTime(Info i1, Info i2) {
	return i1.s < i2.s;
}
int N,usenum[100000];
Info uselist[100000];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &uselist[i].s, &uselist[i].e);
		usenum[i] = 0;
	}
	sort(uselist, uselist + N,CompStartTime);
	priority_queue<Info, vector<Info>, CompEndTime> full;
	priority_queue<int, vector<int>, CompNum> empty;
	int ntime = 0;
	int ct = 0;
	for (int i = 0; i < N; i++) {
		ntime = uselist[i].s;
		while (!full.empty() && full.top().e <= ntime) {
			empty.push(full.top().n);
			full.pop();
		}
		int target;
		if (empty.empty()) {
			target = ct;
			ct++;
		}
		else {
			target = empty.top();
			empty.pop();
		}
		usenum[target]++;
		full.push(Info(0, uselist[i].e, target));

	}
	printf("%d\n", ct);
	for (int i = 0; i < ct; i++) {
		printf("%d ", usenum[i]);
	}
	printf("\n");
	return 0;
}