#include<iostream>
#include<algorithm>
using namespace std;
struct Info {
	int d;
	bool a[30];
	Info() {
		for (int i = 0; i < 30; i++) {
			a[i] = false;
			
		}
		d = 0;
	}
};
int N, K, D, M, A, arr[30];
Info infos[100000];
bool comp(const Info& i1, const Info& i2) {
	return i1.d < i2.d;
}
int main() {
	
	scanf("%d%d%d", &N, &K, &D);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &M, &infos[i].d);
		for (int j = 0; j < M; j++) {
			scanf("%d", &A);
			infos[i].a[A - 1] = true;
		}
	}

	sort(infos, infos + N, comp);
	int s = 0;
	int ans = 0;

	for (int i = 0; i < K; i++) {
		arr[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		while(infos[i].d - infos[s].d > D) {
			for (int j = 0; j < K; j++) {	
				arr[j] -= infos[s].a[j];	
			}
			s++;
		}

		int num = 0;
		for (int j = 0; j < K; j++) {		
			arr[j] += infos[i].a[j];
			num += ((arr[j] > 0) && (arr[j] < i - s + 1));
		}
		ans = max(ans, num * (i - s + 1));
	}
	printf("%d\n", ans);
	return 0;
}