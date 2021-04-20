/*
x��ǥ���� �̵� y��ǥ���� �̵��� ���������� ����

��ǥ ���� -> ������ǥ�� ���ų� ���� ������� �Ÿ� 1������, ū ������� �Ÿ� 1�� ����
��ǥ ���� -> ������ǥ�� ���ų� ū ������� �Ÿ� 1������, ���� ������� �Ÿ� 1�� ����

������ǥ���� ū ���̳� ���� ���� ������ ���ϸ� ��

*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int N, M;
const ll T = 1000000; // ��ǥ -> �ε��� ������
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

	//������ǥ���� ū ��ǥ������ ������
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