/*
  N=N+1

  N/2 ~N-1     �й�






  13
  7~12 ��
  3~6 ��
  2 ��
  1 ��



8
4~7 ��
2~3 ��
1~1 ��

6
3~5 ��
1~2 ��

11
6~10 ��
3~5 ��
2 ��
1 ��
*/



#include<iostream>
using namespace std;
typedef long long ll;
int T;
ll N;
int main()
{
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%lld", &N);
        bool f = true;
        ll s = N + 1, e = N + 1;
        while (s > 1) {
            if (f) {//�й� ����
                e = s - 1;
                s = s / 2 + (s % 2);
            }
            else {//�¸� ����
                e = s - 1;
                s /= 2;
            }
            f = !f;
        }
        printf("#%d %s\n", tc, (!f ? "Bob" : "Alice"));
    }
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}