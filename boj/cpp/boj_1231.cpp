#include<iostream>
#include<algorithm>
using namespace std;
int C, D, M, s[50][10],v[500001];
int main() {
	scanf("%d%d%d", &C, &D, &M);
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < D; j++) {
			scanf("%d", &s[i][j]);
		}
	}
	for (int i = 0; i < D-1; i++) {
		
		for (int j = 0; j <= M; j++) {
			v[j] = j;//�ƹ��͵� �������� ���� ���
			for (int k = 0; k < C; k++) {
				int price = s[k][i];
				if (price > j) continue; //�ش� �ֽ��� ������ �� ���� ���
				v[j] = max(v[j], v[j - price] + s[k][i+1]);
			}
		}
		M = v[M];
	}
	printf("%d\n", M);
	return 0;
}
