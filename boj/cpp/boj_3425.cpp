#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
string s;
int N,op[2][100001],op_sz,trie[26][26][26], st_sz;
ll a,st[1001];
const ll INF = 1000000000;
void Init(string s, int ct) {
	trie[s[0] - 'A'][s[1] - 'A'][s[2] - 'A'] = ct;
}
int retString(string s) {
	return trie[s[0] - 'A'][s[1] - 'A'][s[2] - 'A'];
}
bool ErrorSize(int k) {
	return st_sz < k;
}
bool OverLimit(int index) {
	return st[index] > INF;
}
bool UnderLimit(int index) {
	return st[index] < -INF;
}
bool isZero(int index) {
	return st[index] == 0;
}
ll ABS(ll a) {
	return a < 0 ? -a : a;
}
int main() {
	ios::sync_with_stdio(false);
	op_sz = 0;
	cin >> s;
	Init("NUM", 1);
	Init("POP", 2);
	Init("INV", 3);
	Init("DUP", 4);
	Init("SWP", 5);
	Init("ADD", 6);
	Init("SUB", 7);
	Init("MUL", 8);
	Init("DIV", 9);
	Init("MOD", 10);
	while (s != "QUIT") {
		while (s != "END") {
			op[0][op_sz] = retString(s);
			if (op[0][op_sz] == 1) {
				cin >> op[1][op_sz];
			}
			op_sz++;
			cin >> s;
		}
		cin >> N;

		for (int i = 0; i < N; i++) {
			
			cin >> a;
			bool error = false;
			st[0] = a;
			st_sz = 1;
			for (int j = 0; j < op_sz; j++) {
			
				
				switch (op[0][j]) {
				case 1:
					
					st[st_sz++] = op[1][j];
					break;
				case 2:
					error = ErrorSize(1);
					if (error) {
						break;
					}
					st_sz--;
					break;
				case 3:
					error = ErrorSize(1);
					if (error) {
						break;
					}
					st[st_sz - 1] = -st[st_sz - 1];
					break;
				case 4:
					error = ErrorSize(1);
					if (error) {
						break;
					}
					st[st_sz] = st[st_sz-1];
					st_sz++;
					break;
				case 5:
					error = ErrorSize(2);
					if (error) {
						break;
					}
					a= st[st_sz-1];
					st[st_sz - 1] = st[st_sz - 2];
					st[st_sz - 2] = a;
					break;
				case 6:
					error = ErrorSize(2);
					if (error) {
						break;
					}
					st[st_sz - 2] += st[st_sz - 1];
					st_sz--;
					error=(OverLimit(st_sz - 1) || UnderLimit(st_sz-1));
		
					if (error) {
						break;
					}
					break;
				case 7:
					error = ErrorSize(2);
					if (error) {
						break;
					}
					st[st_sz - 2] = st[st_sz - 2] - st[st_sz - 1];
					st_sz--;
					error = (OverLimit(st_sz - 1) || UnderLimit(st_sz - 1));
					if (error) {
						break;
					}
					
					break;
				case 8:
					error = ErrorSize(2);
					st[st_sz - 2] = st[st_sz - 1] * st[st_sz - 2]; 
					st_sz--;
					error = (OverLimit(st_sz - 1) || UnderLimit(st_sz - 1));
					if (error) {
						break;
					}
					break;
				case 9:
					error = (ErrorSize(2) || isZero(st_sz-1));
				
					if (error) {
						break;
					}
					st[st_sz - 2] = st[st_sz - 2] / st[st_sz - 1];
					st_sz--;
					break;
				case 10:
					error = (ErrorSize(2) || isZero(st_sz-1));
					
					if (error) {
						break;
					}
					st[st_sz - 2] = st[st_sz - 2] % st[st_sz - 1];
					st_sz--;
					break;
				}
			}
			if(error|| st_sz!=1){
				cout << "ERROR\n";
			}
			else {
				cout << st[st_sz - 1] << "\n";
			}
		}
		cout << "\n";
		op_sz = 0;
		cin >> s;
		
	}

	return 0;
}