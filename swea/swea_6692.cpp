#include<iostream>
using namespace std;
int N, T;
double p, x, val;
int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		val = 0;
		for (int i = 0; i < N; i++) {
			scanf("%lf%lf", &p, &x);
			val += x * p;
		}

		printf("#%d %.6lf\n", tc, val);
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}