#include<iostream>
#include<queue>
using namespace std;
struct Info {
	int s, e, seat;
	Info(int s, int e, int seat) {
		this->s = s;
		this->e = e;
		this->seat = seat;
	}
};
struct compare1 {
	bool operator()(Info p1, Info p2) {
		if (p1.s > p2.s) {
			return true;
		}
		else if (p1.s < p2.s) {
			return false;
		}
		else {
			return p1.e > p2.e;
		}
	}
};
struct compare2 {
	bool operator()(Info p1, Info p2) {
		return p1.e > p2.e;
	}
};
int N, T, P,t1,t2;
priority_queue<Info, vector<Info>, compare1> pq1;
priority_queue<Info, vector<Info>, compare2> pq2;
bool isfull[100];
int TimeToMinute(int time){
	return (time / 100 - 9) * 60 + time % 100;
}
int FindEmptySeat() {
	int mdist = 0;
	int ret = 0;
	
	for (int i =0; i <=N-1; i++) {	
		if (!isfull[i]) {
			int ndist = 1;
			for (int j = 1; j <= N; j++) {
				if (i - j < 0 || isfull[i - j]) break;
				ndist++;
			}
			int ndist2 = 1;
			for (int j = 1; j <= N; j++) {
				if (i + j >=N || isfull[i + j]) break;
				ndist2++;
			}	
			if (i == 0) {
				ndist = 101;
			}
			else if (i == N - 1) {
				ndist2 = 101;
			}
			
			int dist = ndist < ndist2 ? ndist : ndist2;
			
			if (mdist < dist) {
				mdist = dist;
				ret = i;
			}
		}
	}
	
	return ret;
}
int main() {
	scanf("%d%d%d", &N, &T, &P);
	for (int i = 0; i < N; i++) {
		isfull[i] = false;
		
	}
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &t1, &t2);
		if (t1 != t2) {
			pq1.push(Info(TimeToMinute(t1), TimeToMinute(t2), -1));
		}
	}
	
	int answer = 0;
	
	for (int i = 0; i < 720; i++) {
		while (!pq2.empty() && pq2.top().e ==i) {
			isfull[pq2.top().seat] = false;
			
			pq2.pop();
		}
		while (!pq1.empty() && pq1.top().s == i) {
			Info t = pq1.top();
			pq1.pop();
			int seatnum = FindEmptySeat();	
			isfull[seatnum] = true;
			
			pq2.push(Info(t.s, t.e, seatnum));
		}
		if (!isfull[P - 1]) {
			answer++;
		}
	}
	printf("%d\n", answer);
	return 0;
}