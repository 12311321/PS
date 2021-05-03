#include<iostream>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
const int csize = 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2;
queue<pii> q;
int arr[3][3],answer_idx;
pii d[4] = { pii(1,0),pii(0,1),pii(-1,0),pii(0,-1) };
bool visit[csize];
int ToNum(int (&arr)[3][3]) {
	int ret = 0;
	for (int i = 0; i < 9; i++) {
		ret *= 10;
		ret += arr[i/3][i%3];
	}
	return ret;
}
void ToArr(int num,int (&arr)[3][3]) {
	for (int i = 8; i >= 0; i--) {
		arr[i/3][i%3] = num % 10;
		num /= 10;
	}
}
int ToIdx(int num) {
	bool v[9];
	for (int i = 0; i < 9; i++) {
		v[i] = true;
	}
	int ret = 0;
	int a = csize / 9;
	int e = 100000000;
	for (int i = 8; i >= 1; i--) {
		
		int b = num / e;
		
		int c = 0;
		v[b] = false;
		for (int j = 0; j < b; j++) {
			c += v[j];
		}
		
		ret += a * c;
		num = num % e;
		e /= 10;
		a /= i;
	
	}
	return ret;
}
int main() {
	answer_idx =ToIdx(123456780);
	for (int i = 0; i < csize; i++) {
		visit[i] = false;
	}
	for (int i = 0; i < 9; i++) {		
		scanf("%d", &arr[i/3][i%3]);	
	}
	int start = ToNum(arr);
	int sidx = ToIdx(start);
	visit[sidx] = true;
	q.push(pii(start, 0));
	int answer = -1;
	
	while (!q.empty()) {
		
		pii t = q.front();
		q.pop();
		int tidx = ToIdx(t.first);
		if (tidx == answer_idx) {
			answer = t.second;
			break;
		}
		ToArr(t.first, arr);
		int zero_r=-1;
		int zero_c = -1;
		for (int i = 0; i < 9; i++) {
			
				if (arr[i/3][i%3] == 0) {
					zero_r = i/3;
					zero_c = i%3;
					break;
				}
				
		}
		for (int i = 0; i < 4; i++) {
			
			int nr = zero_r + d[i].first;
			int nc = zero_c + d[i].second;
			if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3) {
				arr[zero_r][zero_c] = arr[nr][nc];
				arr[nr][nc] = 0;
				int nnum = ToNum(arr);
				int nidx =ToIdx(nnum);
				if (!visit[nidx]) {
					visit[nidx] = true;
					q.push(pii(nnum, t.second + 1));
				}
				arr[nr][nc] = arr[zero_r][zero_c];
				arr[zero_r][zero_c] = 0;
			}
		}

	}
	
	printf("%d\n", answer);
	return 0;
}