#include<iostream>
using namespace std;
int N,l, arr[100000], sz;
int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	sz = 0;
	for (int i = 0; i < N; i++) {
		cin >> l;
		if (sz == 0) {
			arr[sz] = l;
			sz++;
		}
		else {
			if (arr[sz-1] < l) {
				arr[sz++] = l;
			}
			else {
				int s = 0, e = sz - 1;
				while (s != e) {
					int m = (s + e) / 2;
					if (arr[m] >= l) {
						e = m;
					}
					else {
						s = m + 1;
					}
				}
				arr[s] = l;
			}
		}

	}
	cout << N-sz << "\n";
	return 0;
}