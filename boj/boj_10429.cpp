#include<iostream>
#include<string>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
int N, M;
string map[3];
bool visit[3][3];
pii dir[4] = { pii(1,0),pii(-1,0),pii(0,1),pii(0,-1) };
vector<pii> answer;
bool Search(int sum,int num, pii pos);
int main() {
	ios::sync_with_stdio(false);
	answer.clear();
	cin >> N >> M;
	for (int i = 0; i < 3; i++) {
		cin >> map[i];
		for (int j = 0; j < 3; j++) {
			visit[i][j] = false;
		}
	}
	bool ans = false;
	for (int i = 0; i < 9; i++) {
		if (i % 2 == 0) {		
			ans=Search(map[i/3][i%3] - '0', 1, pii(i / 3, i % 3));
		}
		if (ans) {
			break;
		}
	}
	cout << ans << "\n";
	if (ans) {
		for (int i = answer.size() - 1; i >= 0; i--) {
			cout << answer[i].first << " " << answer[i].second << "\n";
		}
	}
	
	return 0;
}
bool Search(int sum,int num, pii pos) {
	if (num == M) {
		if (sum == N) {
			answer.push_back(pos);
			return true;
		}
		else {
			return false;
		}
	}
	visit[pos.first][pos.second] = true;
	bool ret = false;
	for (int i = 0; i < 4; i++) {
		int nr = pos.first + dir[i].first;
		int nc = pos.second + dir[i].second;
		if (nr < 0 || nr>2 || nc < 0 || nc>2 || visit[nr][nc]) continue;
		if ((pos.first + pos.second) % 2 == 1) {//연산자 공간일 경우
			int t = map[nr][nc] - '0';
			if (map[pos.first][pos.second] == '+') {
				ret = Search(sum + t, num + 1,pii(nr,nc));
			}
			else {
				ret = Search(sum - t, num + 1,pii(nr,nc));
			}
		}
		else {//숫자 공간일 경우
			ret=Search(sum, num,pii(nr,nc));
		}
		if (ret) {
			answer.push_back(pos);
			return true;
		}
	}
	visit[pos.first][pos.second] = false;
	return false;
}