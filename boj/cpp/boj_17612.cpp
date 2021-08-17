#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
struct Info {
	int id;
	int time;
	int num;
	Info(int id, int time, int num) {
		this->id = id;
		this->time = time;
		this->num = num;
	}
};
struct compare1 {
	bool operator()(Info i1, Info i2) {
		return i1.num > i2.num;
	}
};
struct compare2 {
	bool operator()(Info i1, Info i2) {
		if (i1.time > i2.time) {
			return true;
		}
		else if (i1.time < i2.time) {
			return false;
		}
		else {
			return i1.num < i2.num;
		}
	}
};
priority_queue<Info, vector<Info>, compare1> wait;
priority_queue<Info, vector<Info>, compare2> process;
int N, k,id,w;
int main() {
	scanf("%d%d", &N, &k);
	for (int i = 0; i < k; i++) {
		wait.push(Info(-1, -1, i));
	}
	ll answer = 0,ct=1;
	int ntime = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &id, &w);
		if(wait.empty()) {
			ntime = process.top().time;
			while (!process.empty() &&ntime == process.top().time) {
				Info t = process.top();
				process.pop();
				answer += (ct * (ll)t.id);
				ct++;
				wait.push(Info(-1, -1, t.num));

			}
		}
		process.push(Info(id, ntime + w, wait.top().num));
		wait.pop();
	}
	while (!process.empty()) {
		Info t = process.top();
		process.pop();
		answer += (ct * (ll)t.id);
		ct++;
	}
	printf("%lld\n", answer);
	return 0;
}