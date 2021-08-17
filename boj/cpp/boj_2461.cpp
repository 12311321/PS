#include<iostream>
#include<algorithm>
using namespace std;
struct Info {
	int s, c;
};
int N, M, cn, carr[1000];
Info student[1000000];
bool CompInfo(const Info& i1, const Info& i2);
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &student[i * M + j].s);
			student[i * M + j].c = i;
		}
	}
	cn = 0;
	for (int i = 0; i < N; i++) {
		carr[i] = 0;
	}

	sort(student, student + N * M, CompInfo);
	int idx1 = 0, idx2 = 0, ans = (1 << 30);
	while (idx1 < N * M) {
		while (idx2 < N * M && cn < N) {
			carr[student[idx2].c]++;
			if (carr[student[idx2].c] == 1) {
				cn++;
			}
			idx2++;
		}

		if (idx2 == N * M && cn < N) break;
		ans = min(ans, student[idx2 - 1].s - student[idx1].s);
		carr[student[idx1].c]--;
		if (carr[student[idx1].c] == 0) {
			cn--;
		}
		idx1++;
	}
	printf("%d\n", ans);
	return 0;
}
bool CompInfo(const Info& i1, const Info& i2) {
	return i1.s < i2.s;
}