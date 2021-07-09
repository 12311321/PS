#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pos {
	ll x, y;
	pos operator-(pos t) {
		return { x - t.x, y - t.y };
	}
};
pos p1, p2, p3, p4;
ll CCW(pos v1, pos v2);
void sol();
int main() {
	scanf("%lld%lld%lld%lld", &p1.x, &p1.y, &p2.x, &p2.y);
	scanf("%lld%lld%lld%lld", &p3.x, &p3.y, &p4.x, &p4.y);
	if (p1.x > p2.x) {
		pos t = p1;
		p1 = p2;
		p2 = t;

	}
	if (p3.x > p4.x) {
		pos t = p3;
		p3 = p4;
		p4 = t;
	}
	sol();
	return 0;
}
ll CCW(pos v1, pos v2) {
	ll r = v1.x * v2.y - v2.x * v1.y;
	if (r == 0) {
		return 0;
	}
	else if (r > 0) {
		return 1;
	}
	else {
		return -1;
	}
}
void sol() {
	ll r1 = CCW(p2 - p1, p3-p1);
	ll r2 = CCW(p2 - p1, p4-p1);
	ll min_y1 = min(p1.y, p2.y);
	ll max_y1 = max(p1.y, p2.y);
	ll min_y2 = min(p3.y, p4.y);
	ll max_y2 = max(p3.y, p4.y);
	
	if (r1 == 0 && r2 == 0) {//老流急老 版快
		if (p2.x == p1.x) {//x=k
			if (p1.x == p3.x) {//鞍篮 绵老 版快
				if (max_y1 == min_y2) {
					printf("1\n");
					printf("%lld %lld\n", p1.x, max_y1);
				}
				else if (max_y2 == min_y1) {
					printf("1\n");
					printf("%lld %lld\n", p1.x, max_y2);
				}
				else if ((min_y1 >= min_y2 && min_y1 <= max_y2) || (min_y2 >= min_y1 && min_y2 <= max_y1)) {
					printf("1\n");
				}
				else {
					printf("0\n");
				}
			}
			else {
				printf("0\n");
			}
		}
		else {
			if (p2.x == p3.x) {
				printf("1\n");
				printf("%lld %lld\n", p2.x, p2.y);
			}
			else if (p1.x == p4.x) {
				printf("1\n");
				printf("%lld %lld\n", p1.x, p1.y);

			}
			else if (p3.x >= p1.x && p3.x <= p2.x || p1.x >= p3.x && p1.x <= p4.x) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}


		}
	}
	else if (r1 * r2 == 0) {
		if (r1 == 0) {
			if (p3.x >= p1.x && p3.x <= p2.x) {
				printf("1\n");
				printf("%lld %lld\n", p3.x, p3.y);
			}
			else {
				printf("0\n");
			}
		}
		else {
			if (p4.x >= p1.x && p4.x <= p2.x) {
				printf("1\n");
				printf("%lld %lld\n", p4.x, p4.y);
			}
			else {
				printf("0\n");
			}
		}
	}
	else if (r1 * r2 == -1) {
		if (p2.x == p1.x) {
			double xpos = p1.x;
			double s2 = (double)(p4.y - p3.y) / (p4.x - p3.x);
			double a2 = (double)p3.y - s2 * p3.x;
			double ypos = s2 * xpos + a2;
			if (xpos >= p3.x && xpos <= p4.x && ypos >= min_y1 && ypos <= max_y1) {
				printf("1\n");
				printf("%.10lf %.10lf\n",xpos,ypos);
			}
			else {
				printf("0\n");
			}
		}
		else if (p3.x == p4.x) {
			double xpos = p3.x;
			double s1 = (double)(p2.y - p1.y) / (p2.x - p1.x);
			double a1 = (double)p1.y - s1 * p1.x;
			double ypos = s1 * xpos + a1;
			if (xpos >= p1.x && xpos <= p2.x && ypos >= min_y2 && ypos <= max_y2) {
				printf("1\n");
				printf("%.10lf %.10lf\n", xpos, ypos);
			}
			else {
				printf("0\n");
			}
		}
		else {
			double s1 = (double)(p2.y - p1.y) / (p2.x - p1.x);
			double s2 = (double)(p4.y - p3.y) / (p4.x - p3.x);
			double a1 = (double)p1.y - s1 * p1.x;
			double a2 = (double)p3.y - s2 * p3.x;
			double xpos = (a2 - a1) / (s1 - s2);

			if (xpos >= p1.x && xpos <= p2.x && xpos >= p3.x && xpos <= p4.x) {
				printf("1\n");
				printf("%.10lf %.10lf\n", xpos, s1 * xpos + a1);
			}
			else {
				printf("0\n");
			}
		}
	}
	else {
		printf("0\n");
	}

}