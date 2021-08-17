#include<iostream>
#include<algorithm>
using namespace std;
struct Edge {
	int s;
	int e;
	int c;
};
int N, M,A,B,C,par[10000],d[10000];
Edge elist[100000];
bool Compare(const Edge e1,const Edge e2) {
	return e1.c > e2.c;
}
int Find(int k) {
	if (k == par[k]) {
		return k;
	}
	return (par[k] = Find(par[k]));
}
void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb) {
		return;
	}

	if (d[pa] < d[pb]) {
		par[pa] = pb;
	}
	else if (d[pa] > d[pb]) {
		par[pb] = pa;
	}
	else {
		par[pb] = pa;
		d[pa]++;
	}
	
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		par[i] = i;
		d[i] = 1;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &A, &B, &C);
		elist[i].s = A-1;
		elist[i].e = B-1;
		elist[i].c = C;
	}
	scanf("%d%d", &A, &B);
	A--;
	B--;
	sort(elist, elist + M, Compare);
	for (int i = 0; i < M; i++) {
		Union(elist[i].s, elist[i].e);
		if (Find(A) == Find(B)) {
			printf("%d\n", elist[i].c);
			break;
		}
	}
	return 0;
}
/*
6 6
1 2 12
2 3 7
2 4 5
3 5 8
4 6 9
4 5 10
1 6



*/