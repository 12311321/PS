/*
�ҵ��� ������� ��

�ð� T�ȿ� ��� �ҵ��� ���� ���� �� �ִ� ���� ���� ����ũ�� K�� ���ϴ� ��

K=N�� �� ��� �Ұ� ���� �����ٴ°� �����(d(i) <= T)
*/


#include<iostream>
#include<queue>
using namespace std;
int N, T,d[10000];


struct comp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int getT(int k) {
	priority_queue<int, vector<int>, comp> pq;
	int time = 0;
	for (int i = 0; i < N; i++) {
		while(pq.size() >= k) {
			time = pq.top();	
			pq.pop();
		}
		pq.push(d[i] + time);

	}
	while (!pq.empty()) {
		time = pq.top();
		pq.pop();
	}

	return time;
}
int main() {
	
	scanf("%d%d", &N, &T);
	for (int i = 0; i < N; i++) {
		scanf("%d", &d[i]);
	}
	int s = 1, e = N,ans=N;
	while (s <= e) {
		int m = (s + e) / 2;
		int r = getT(m);
		if (r <= T) {
			ans = m;
			e = m - 1;
		}
		else {
			s = m + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}