
#include<iostream>
#include<algorithm>
using namespace std;
int D, A, B;
int main() {
	scanf("%d%d%d", &D, &A, &B);
	if (A > B) {
		swap(A, B);
	}
	int bnum = D / B + (D % B != 0);
	int n = B * bnum;
	int ans = min(A*(D/A+(D%A!=0)),n);
	int m = B - A * (B / A);
	if (n - D > A) {
		n -= B;
		bnum--;
		n += A * ((D-n) / A + ((D-n) % A != 0));

	}
	if (bnum < 100000) {
		while (bnum > 0) {
			if (n > D) {
				ans = min(n, ans);
				n -= m;
				bnum--;

			}
			else if (n < D) {
				n += A;
			}
			else {
				ans = D;
				break;
			}
		}
	}
	else {
		bool *check = new bool[A + 1];
		for (int i = 0; i <= A; i++) {
			check[i] = false;
		}
		while (bnum > 0) {	
			if (n > D) {
				if (n-D<=A && check[n - D]) {
					break;
				}
				if (n - D <= A) {
					check[n - D] = true;
				}
				ans = min(n, ans);
				n -= m;
				bnum--;

			}
			else if (n < D) {
				n += A;
			}
			else {
				ans = D;
				break;
			}


		}
		delete[] check;
	}
	printf("%d\n", ans);
	return 0;
}