#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
string str[100000];
int N;
double Search(int s, int e,int idx);
int main() {
	ios::sync_with_stdio(false);
	cout << fixed;
	cout.precision(2);
	while (cin>>N) {
		for (int i = 0; i < N; i++) {
			cin >> str[i];
		}
		sort(str, str + N);
		int sidx = 0;
		double ret = N;
		for (int i = 1; i < N; i++) {
			if (str[i][0] != str[sidx][0]) {
				ret += Search(sidx, i - 1, 0);
				sidx = i;
			}
		}
		ret += Search(sidx, N - 1, 0);
		cout << ret / N << "\n";	
	}

	return 0;
}
double Search(int s, int e,int idx) {
	if (s == e) {
		return 0;
	}
	int sidx = s;
	if (str[s].size() == idx) {
		sidx++;
	}
	double ret = 0;
	double temp = 0;
	for (int i = s+1; i <= e; i++) {
		if (str[sidx][idx] != str[i][idx]) {
			ret += (double)i - sidx;
			temp += (double)i - sidx;
			ret += Search(sidx, i - 1, idx + 1);
			sidx = i;
		}

	}
	if (sidx != s) {
		temp += (double)e - sidx + 1;
		ret += (double)e - sidx + 1;
	}
	ret += Search(sidx, e, idx + 1);
	return ret;
}