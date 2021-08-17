#include<iostream>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
int N, M,A[100][100],d,s,visit[100][100],cloud_sz;
pii dir[8] = { pii(0,-1),pii(-1,-1),pii(-1,0),pii(-1,1),pii(0,1),pii(1,1),pii(1,0),pii(1,-1) };
pii cloud[2501];
void Move(int d, int s,int ct) {
	
	
	for(int i=0; i<cloud_sz; i++){
		pii t = cloud[i];

		//1�� 
		int nr =(N+t.first + dir[d].first * s)%N;
		int nc =(N+t.second + dir[d].second * s)%N;

		//4�� ������ �̵��Ѱ����� ����
		cloud[i] = pii(nr, nc);

		//2��
		A[nr][nc]++;

		//5�� ������ ����� ĭ ��ǥüũ
		visit[nr][nc] = ct;
		
	}
	
	//4��
	for (int i = 0; i < cloud_sz; i++) {
		for (int j = 1; j < 8; j += 2) {
			int nr = cloud[i].first + dir[j].first;
			int nc = cloud[i].second + dir[j].second;

			//����ų� ���� ���� ���
			if (nr < 0 || nr >= N || nc < 0 || nc >= N || A[nr][nc] == 0) continue;

			A[cloud[i].first][cloud[i].second]++;
		}
	}
	

}
void makeCloud(int ct) {
	cloud_sz = 0;//3��

	//5��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] >= 2 && visit[i][j] != ct) {
				A[i][j] -= 2;//���� �پ��
				cloud[cloud_sz++] = pii(i, j);//��������
			}
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
			visit[i][j] = -1;
		}
	}
	cloud_sz = 4;
	cloud[0]=(pii(N - 1, 0));
	cloud[1]=(pii(N - 1, 1));
	cloud[2]=(pii(N - 2, 0));
	cloud[3]=(pii(N - 2, 1));
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &d, &s);
		Move(d - 1, s%N,i);//N�� �̵��ϸ� �����ڸ��� ���ƿ�
		makeCloud(i);
		
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer += A[i][j];
		}
	}
	printf("%d\n", answer);
	return 0;
}