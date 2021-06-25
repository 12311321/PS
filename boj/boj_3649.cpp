#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
int c, n;
struct Posinfo {
	pii pos;
	int idx;
};
Posinfo posinfo[2000];
void Swap(int idx1, int idx2);
bool CompPos(const Posinfo &p1,const Posinfo &p2);
int OuterProduct(const pii& p1, const pii& p2);
int main() {
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &posinfo[i].pos.first, &posinfo[i].pos.second);
			posinfo[i].idx = i;
			if (posinfo[i].pos.second < posinfo[0].pos.second) {
				Swap(i, 0);
			}
			else if (posinfo[i].pos.second == posinfo[0].pos.second) {
				if (posinfo[i].pos.first < posinfo[0].pos.first) {
					Swap(i, 0);
				}
			}
		}
		sort(posinfo + 1, posinfo + n, CompPos);
		int idx=n-1;
		for (int i = n - 1; i >= 2; i--) {
			pii v1 = pii(posinfo[i].pos.first - posinfo[0].pos.first, posinfo[i].pos.second - posinfo[0].pos.second);
			pii v2 = pii(posinfo[i-1].pos.first - posinfo[0].pos.first, posinfo[i-1].pos.second - posinfo[0].pos.second);
			if (OuterProduct(v1,v2)!=0) {
				break;
			}
			idx--;

		}
		reverse(posinfo + idx, posinfo + n);
		for (int i = 0; i < n; i++) {
			printf("%d ", posinfo[i].idx);
		}
		printf("\n");
	}

	return 0;
}
void Swap(int idx1, int idx2) {
	Posinfo temp = posinfo[idx1];
	posinfo[idx1] = posinfo[idx2];
	posinfo[idx2] = temp;
}
bool CompPos(const Posinfo& p1, const Posinfo& p2) {
	pii v1 = pii(p1.pos.first - posinfo[0].pos.first, p1.pos.second - posinfo[0].pos.second);
	pii v2 = pii(p2.pos.first - posinfo[0].pos.first, p2.pos.second - posinfo[0].pos.second);
	int r = OuterProduct(v1, v2);
	if (r == 0) {
		return v1.first * v1.first + v1.second * v1.second<v2.first*v2.first+v2.second*v2.second;
	}
	return r > 0;

	
}
int OuterProduct(const pii &p1,const pii &p2) {
	return p1.first * p2.second - p1.second * p2.first;
}