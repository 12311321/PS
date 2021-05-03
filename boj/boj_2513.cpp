#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, K, S,p,n;
vector<pii> leftPos,rightPos;
int main() {
	scanf("%d%d%d", &N, &K, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &p, &n);
		p < S ? leftPos.push_back(pii(S - p, n)) : rightPos.push_back(pii(p - S, n));
	}
	sort(leftPos.begin(), leftPos.end());
	sort(rightPos.begin(), rightPos.end());
	int answer = 0;
	int empty = K;
	int idx = leftPos.size()-1;
	while (idx >=0) {
		answer += leftPos[idx].first * 2;
		while(idx>=0 && empty - leftPos[idx].second >= 0) {
			empty -= leftPos[idx].second;
			idx--;
		}
		if (idx >= 0) {
			leftPos[idx].second -= empty;
		}
		
		empty = K;
		

	}
	
	empty = K;
	idx = rightPos.size() - 1;
	while (idx >= 0) {
		answer += rightPos[idx].first * 2;
		while (idx >= 0 && empty - rightPos[idx].second >= 0) {
			empty -= rightPos[idx].second;
			idx--;
		}
		if (idx >= 0) {
			rightPos[idx].second -= empty;
		}
		empty = K;


	}
	printf("%d\n", answer);
	return 0;
}