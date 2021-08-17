/*
x좌표에서 이동 y좌표에서 이동을 독립적으로 생각

좌표 증가 -> 현재좌표랑 같거나 작은 점들과의 거리 1씩증가, 큰 점들과의 거리 1씩 감소
좌표 감소 -> 현재좌표랑 같거나 큰 점들과의 거리 1씩증가, 작은 점들과는 거리 1씩 감소

현재좌표보다 큰 점이나 작은 점의 개수만 구하면 됨

*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int N, M;
const ll T = 1000000; // 좌표 -> 인덱스 보정값
ll input_x,input_y,pos_x[T*2+1], pos_y[T*2+1],dist;
string s;
ll ABS(ll a) {
	return a < 0 ? -a : a;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> N>>M;
	dist = 0;
	for (int i = 0; i <= 2*T; i++) {
		pos_x[i] = 0;
		pos_y[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> input_x>>input_y;
		dist += ABS(input_x) + ABS(input_y);
		pos_x[input_x + T]++;
		pos_y[input_y + T]++;
	}

	//작은좌표에서 큰 좌표순으로 누적합
	for (int i = 1; i <= 2 * T; i++) {
		pos_x[i] = pos_x[i - 1] + pos_x[i];
		pos_y[i] = pos_y[i - 1] + pos_y[i];
		
	}
	
	ll nx = 0;
	ll ny = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case 'S':
			dist -= (pos_y[2 * T] - pos_y[ny+T]);
			dist += pos_y[ny+T];
			ny++;
			break;
		case 'J':
			ny--;
			dist += pos_y[2 * T] - pos_y[ny + T];
			dist -= pos_y[ny + T];
			break;
		case 'I':
			dist -= pos_x[2 * T] - pos_x[nx + T];
			dist += pos_x[nx + T];
			nx++;
			break;
		case 'Z':
			nx--;
			dist += pos_x[2 * T] - pos_x[nx + T];
			dist -= pos_x[nx + T];
			break;
		}
		cout << dist << "\n";
	}
	return 0;
}