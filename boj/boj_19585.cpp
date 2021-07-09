#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
struct Node {
	bool isleaf;
	map<char, Node*> next;
	Node() {
		isleaf = false;
		next.clear();
	}
};
class Trie {
public:
	Node root;
	void InsertStr(const char* s, bool isreverse) {
		Node* pos = &root;
		int slen = strlen(s);
		if (!isreverse) {
			for (int i = 0; i < slen; i++) {
				if (pos->next.count(s[i]) == 0) {
					pos->next[s[i]] = new Node();
				}
				pos = pos->next[s[i]];
			}
			pos->isleaf = true;
		}
		else {
			for (int i = 0; i < slen; i++) {
				if (pos->next.count(s[slen - 1 - i]) == 0) {
					pos->next[s[slen - 1 - i]] = new Node();
				}
				pos = pos->next[s[slen - 1 - i]];
			}
			pos->isleaf = true;
		}
	}

};
int C, N, Q;
string s;
bool Search(Trie& c, Trie& n, const char* s);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C >> N;
	Trie ctrie, ntrie;
	for (int i = 0; i < C; i++) {
		cin >> s;
		ctrie.InsertStr(s.c_str(), false);

	}
	for (int i = 0; i < N; i++) {
		cin >> s;
		ntrie.InsertStr(s.c_str(), true);
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> s;

		cout << (Search(ctrie, ntrie, s.c_str()) ? "Yes" : "No") << "\n";
	}
	return 0;
}
bool Search(Trie& c, Trie& n, const char* s) {
	bool visit[2001];
	int slen = strlen(s);
	for (int i = 0; i <= slen; i++) {
		visit[i] = false;
	}
	Node* pos = &c.root;
	for (int i = 0; i < slen; i++) {
		if (pos->next.count(s[i]) == 0) {
			break;
		}
		pos = pos->next[s[i]];
		if (pos->isleaf) {
			visit[i + 1] = true;
		}
	}
	pos = &n.root;
	for (int i = 0; i < slen; i++) {
		if (pos->next.count(s[slen - 1 - i]) == 0) {
			break;
		}
		pos = pos->next[s[slen - 1 - i]];
		if (pos->isleaf) {
			if (visit[slen - (i + 1)]) {
				return true;
			}
		}
	}
	return false;
}