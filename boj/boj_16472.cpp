#include<iostream>
#include<string>
#include<queue>
using namespace std;
int N,alpn[26];
string s;
queue<int> q;
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> s;
	for (int i = 0; i < 26; i++) {
		alpn[i] = 0;
	}
	int numAlp = 0;
	int answer = 0;
	for (int i = 0; i < s.size(); i++) {
		q.push(s[i]-'a');
		alpn[s[i] - 'a']++;
		if (alpn[s[i] - 'a'] == 1) { // ��Ͽ� ���� ���ο� ���Ĺ� ������ ������ ���
			numAlp++;
		}
		while (numAlp > N) { // ���Ĺ� ������ N�� �Ѿ ��� �տ������� ������
			int t = q.front();
			q.pop();
			alpn[t]--;
			if (alpn[t] == 0) {
				numAlp--;
			}
		}
		answer = answer < q.size() ? q.size() : answer;
	}
	cout << answer << "\n";
	return 0;
}