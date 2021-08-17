/*
  ��� n�� ���� ��
  �κм��� A1,A2,A3, ... ,A(n-1)
  �κм����� ���� n���� ��� ����
  n�� ��� �����°��� ���� ���������� 0~n-1������ ������ų �� ����
  �׸����ϰ� �ִ񰪸� ���ϰ� �� �� ���� ������ŭ ����

  ���������ϴ� ��
  �ִ񰪸� ���ϹǷ� ������ n, n-1 ,n-2 ,n-3 ...(n+1)., 1 , n+2, n+3, ... , N
  �̶� K���� n+1�� ���� ���(���̿� ������ ���)�� ��� �������� 0��
*/



#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll N, K;
vector<ll> ans;
int main() {
	scanf("%lld%lld", &N, &K);
	ans.clear();
	for (ll i = 0; i < N; i++) {
		if (K > i) {
			K -=i;
		}
		else {	
			for (ll j = i-1; j >= K; j--) {
				ans.push_back(j + 1);
			}
			ans.push_back(i+1);
			for (ll j = K-1; j>=0; j--) {
				ans.push_back(j + 1);
			}
			for (ll j = i + 1; j < N; j++) {
				ans.push_back(j+1);
			}
			K = 0;
			break;
		}
	}
	if (K > 0) {
		printf("-1");
	}
	else {
		for (int i = 0; i < ans.size(); i++) {
			printf("%lld ", ans[i]);
		}
	}
	printf("\n");
	return 0;
}