#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
struct Pos {
	int x, y;
	Pos operator-(Pos p) {
		return { x - p.x,y - p.y };
	}
};
int n;
Pos p[100000], firstp;
vector<Pos>st;
int OuterProduct(Pos v1, Pos v2);
int ExDist(Pos v);
bool CompPos(Pos p1, Pos p2);
void Scan();
double Pdist(Pos p1, Pos p2, Pos p3);
double Search();
int main() {
	int tc = 1;
	scanf("%d", &n);
	while (n != 0) {
		firstp.y = 10001;

		for (int i = 0; i < n; i++) {
			scanf("%d%d", &p[i].x, &p[i].y);
			if (firstp.y > p[i].y) {
				firstp = p[i];
			}
			else if (firstp.y == p[i].y && firstp.x > p[i].x) {
				firstp = p[i];
			}
		}
		sort(p, p + n, CompPos);
		Scan();
		printf("Case %d: %.2lf\n", tc++, ceil(100 * Search()) / 100);
		scanf("%d", &n);

	}
	return 0;
}
int OuterProduct(Pos v1, Pos v2) {
	return v1.x * v2.y - v2.x * v1.y;
}
int ExDist(Pos v) {
	return v.x * v.x + v.y * v.y;
}
bool CompPos(Pos p1, Pos p2) {
	Pos v1 = p1 - firstp, v2 = p2 - firstp;
	int r = OuterProduct(v1, v2);
	if (r == 0) {
		return ExDist(v1) < ExDist(v2);
	}
	return r > 0;
}
void Scan() {
	st.clear();
	st.push_back(p[0]);
	st.push_back(p[1]);
	for (int i = 2; i <= n; i++) {
		while (st.size() >= 2) {
			Pos v1 = st.back() - st[st.size() - 2];
			Pos v2 = p[i % n] - st[st.size() - 2];
			int r = OuterProduct(v1, v2);
			if (r > 0) {
				break;
			}
			st.pop_back();
		}
		st.push_back(p[i % n]);
	}
	st.pop_back();
}
double Pdist(Pos p1, Pos p2, Pos p3) {
	double area2 = abs((double)p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.x * p3.y - p2.x * p1.y - p3.x * p2.y);
	double length = sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y));
	return area2 / length;
}
double Search() {
	double ret = 10000000;
	for (int i = 0; i < st.size(); i++) {
		double maxval = 0;
		for (int j = 0; j < st.size(); j++) {
			maxval = max(maxval, Pdist(st[j], st[i], st[(i + 1) % st.size()]));
		}
		ret = min(ret, maxval);
	}

	return ret;
}