#include<iostream>
using namespace std;
class SGT {
public:
	int* tree;
	int* leaf;
	int N;
	SGT(int N) {
		this->N = N;	
		Init();
	}
	~SGT() {
		delete[] tree;
		delete[] leaf;
	}
	void Init() {
		int sz = 2;
		while (sz < N) {
			sz *= 2;
		}
		tree = new int[sz * 2];
		leaf = new int[N + 1];
		for (int i = 1; i < sz * 2; i++) {
			tree[i] = 0;
		}
		for (int i = 1; i <= N; i++) {
			int s = 1, e = N, pos = 1;
			while (1) {
				if (s == e) {
					leaf[i] = pos;
					break;
				}
				int m = (s + e) / 2;
				if (m >= i) {
					e = m;
				}
				else {
					s = m + 1;
				}
				pos = pos * 2 + (m < i);
			}
		}
	}
	void InsertData(int data) {
		int s = 1, e = N, pos = 1;
		while (1) {
			tree[pos]++;
			if (s == e) {
				break;
			}
			int m = (s + e) / 2;
			if (m >= data) {
				e = m;
			}
			else {
				s = m + 1;
			}
			pos = pos * 2 + (m < data);
		}
	}
	void DeleteData(int data) {
		int pos = leaf[data];	
		while (pos > 0) {
			tree[pos]--;
			pos /= 2;
		}
	}
	int SearchEdge(int s, int e, int pos, int num) {
		if (pos == 1 && tree[pos] < num) {
			return -1;
		}
		if (s == e) {
			return s;
		}
		int m = (s + e) / 2;
		if (tree[pos * 2] >= num) {
			return SearchEdge(s, m, pos * 2, num);
		}
		else {
			return SearchEdge(m + 1, e, pos * 2 + 1, num - tree[pos * 2]);
		}
	}
	int SearchVertexNum(int s, int e, int pos, int num) {
		if (tree[pos] == 0) {
			return -1;
		}
		if (s == e) {
			return s;
		}
		int m = (s + e) / 2;
		if (m < num) {
			
			return SearchVertexNum(m + 1, e, pos * 2 + 1, num);
			
		}
		else {
			int r = SearchVertexNum(m + 1, e, pos * 2 + 1, m + 1);
			
			if (r == -1) {
				return SearchVertexNum(s, m, pos * 2, num);
			}
			else {
				return r;
			}
		}
		
	}
};
int K,a[200000];

int main() {
	scanf("%d", &K);
	int max_n=0;
	for (int i = 0; i < K; i++) {
		scanf("%d", &a[i]);
		max_n = max_n < a[i] ? a[i] : max_n;
	}
	SGT sgtRight(max_n);
	SGT sgtLeft(max_n);
	for (int i = 0; i < K; i++) {
		sgtRight.InsertData(a[i]);
	}
	int answer[2] = { -1,-1 };
	for (int i = 0; i < K; i++) {
		sgtRight.DeleteData(a[i]);
		int vlimit = sgtRight.SearchEdge(1,max_n,1,a[i]*2);
		if (vlimit != -1) {

			int vn = sgtLeft.SearchVertexNum(1, max_n, 1, vlimit);
			if (vn != -1) {

				if (vn > answer[0]) {
					answer[0] = vn;
					answer[1] = a[i];
				}
				else if (vn == answer[0] && answer[1]<a[i]) {
					answer[1] = a[i];
				}
			}
		}
		sgtLeft.InsertData(a[i]);
	}
	printf("%d ", answer[0]);
	if (answer[0] != -1) {
		printf("%d\n", answer[1]);
	}
	return 0;
}