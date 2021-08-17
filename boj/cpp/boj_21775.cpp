#include <iostream>
#include<set>
using namespace std;
struct OpCard {
	int id;
	char name[10];
	int n;
};
int N, T, turn[500000];
OpCard op[500000], *player[500001];
set<int> st;
int main() {
	scanf("%d%d", &N, &T);
	for (int i = 1; i <= N; i++) {
		player[i] = NULL;
	}
	for (int i = 0; i < T; i++) {
		scanf("%d", &turn[i]);
	}
	for (int i = 0; i < T; i++) {
		scanf("%d", &op[i].id);
		scanf("%s", op[i].name);

		if (op[i].name[0] != 'n') {
			scanf("%d", &op[i].n);
		}

	}
	st.clear();
	int op_idx = 0;
	for (int i = 0; i < T; i++) {
		OpCard* nop;
		if (player[turn[i]] != NULL) {
			nop = player[turn[i]];
		}
		else {
			nop = &op[op_idx++];
		}
		switch (nop->name[0]) {
		case 'a':
			
			if (st.find(nop->n)==st.end()) {
				st.insert(nop->n);
				player[turn[i]] = NULL;
			}
			else {
				player[turn[i]] = nop;
			}
			break;
		case 'r':
			st.erase(st.find(nop->n));
			break;
		}
		printf("%d\n", nop->id);
	}

	return 0;
}