#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int t, a, b,visit[1000100], ans;
void search(int idx,int a,int b,int k) {
	if (k > ans) return;
	if (idx == 25) {
		ans = min(ans, k + 1);
		return;
	}
	int abit = (a & (1 << idx));
	int bbit = (b & (1 << idx));
	if (abit !=0 && bbit == 0) {
		int t = (1 << idx) - (b % (1 << idx))+(a%(1<<idx));
		search(idx + 1, a,b+t, k + t);
		t = (1 << (idx + 1)) - (a % (1 << (idx + 1)));
		search(idx + 1, a + t,b, k + t);
	}
	else {
		search(idx + 1, a,b,k);
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> a >> b;
		ans = b-a;
		search(0, a,b,0);
		cout << ans << "\n";
	}
	return 0;
}