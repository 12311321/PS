#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
struct Info {
	ll s;
	ll e;
	int num;
	Info() {};
	Info(ll s, ll e, int num) {
		this->s = s;
		this->e = e;
		this->num = num;
	}
};
bool CompStartTime(Info i1, Info i2) {
	return i1.s < i2.s;
}
struct CompEndTime {
	bool operator()(Info i1, Info i2) {
		return i1.e > i2.e;
	}
};
int T, B, month_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
ll C;
ll opTime(ll a, ll b) {
	ll min =a % 100 + b%100;
	a /= 100;
	ll hour = a % 100+ b/100;
	a /= 100;
	ll day = a % 100;
	a /= 100;
	ll month = a % 100;
	a /= 100;
	ll year = a;
	if (min >= 60) {
		min %= 60;
		hour++;
	}
	if (hour >= 24) {
		hour %= 24;
		day++;
	}
	int t = month_day[month - 1];
	if (year % 4 == 0 && month == 2) {
		t++;
	}
	if (day > t) {
		day = 1;
		month++;
	}
	if (month == 13) {
		year++;
		month = 1;
	}
	a = year;
	a *= 100;
	a += month;
	a *= 100;
	a += day;
	a *= 100;
	a += hour;
	a *= 100;
	a += min;

	return a;
}
ll StrToLl(string s1, string s2) {
	ll ret = 0;
	for (int i = 0; i < s1.size(); i++) {

		if (s1[i] >= '0' && s1[i] <= '9') {
			ret *= 10;
			ret += (s1[i] - '0');
		}
	}
	for (int i = 0; i < s2.size(); i++) {

		if (s2[i] >= '0' && s2[i] <= '9') {
			ret *= 10;
			ret += (s2[i] - '0');
		}
	}
	return ret;
}
Info input[5000];
string s1, s2;
int main() {
	
	ios::sync_with_stdio(false);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> B >> C;
		
		ll h = C / 60;
		ll m = C % 60;
		C = h * 100 + m;
		for (int i = 0; i < B; i++) {
			cin >> s1;
			cin >> s1 >> s2;
			input[i].s = StrToLl(s1, s2);
			cin >> s1 >> s2;
			input[i].e = StrToLl(s1, s2);
		}
		sort(input, input + B, CompStartTime);
		int ct = 0;
		queue<int> q;
		priority_queue<Info, vector<Info>, CompEndTime> pq;
		for (int i = 0; i < B; i++) {
			ll ntime = input[i].s;
			while (!pq.empty() && pq.top().e <= ntime) {
				q.push(pq.top().num);
				pq.pop();
			}
			int target;
			if (q.empty()) {
				target = ct;
				ct++;
			}
			else {
				target = q.front();
				q.pop();
			}

			pq.push(Info(0, opTime(input[i].e, C), target));

		}
		printf("%d\n", ct);
	}
	return 0;
}