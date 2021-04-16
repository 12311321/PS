/*
   (a)  k   (b)
*/

#include <string>
#include <vector>

using namespace std;
const int INF = 1000000001;
class SGT {
public:
    int* tree;
    int N;
    SGT(int N) {
        this->N = N;
        int sz = 2;
        while (sz <= N) {
            sz *= 2;
        }
        tree = new int[sz * 2 + 1];
        for (int i = 1; i <= sz * 2; i++) {
            tree[i] = INF;
        }
    }
    ~SGT() {
        delete[] tree;
    }
    void Insert(int index, int data) {
        int s = 1, e = N, pos = 1;
        while (1) {
            tree[pos] = tree[pos] > data ? data : tree[pos];
            if (s == e) {
                break;
            }
            int m = (s + e) / 2;
            if (m >= index) {
                e = m;
            }
            else {
                s = m + 1;
            }
            pos = pos * 2 + (m < index);
        }
    }
    int Search(int s, int e, int pos, int fs, int fe) {

        if (s == fs && e == fe) {
            return tree[pos];
        }
        int ret = INF;
        int m = (s + e) / 2;
        if (m >= fs) {
            int r = Search(s, m, pos * 2, fs, fe < m ? fe : m);
            ret = ret > r ? r : ret;
        }
        if (m + 1 <= fe) {
            int r = Search(m + 1, e, pos * 2 + 1, fs > m + 1 ? fs : m + 1, fe);
            ret = ret > r ? r : ret;
        }
        return ret;
    }
};
int solution(vector<int> a) {
    int answer = 0;
    SGT sgt(a.size());
    for (int i = 0; i < a.size(); i++) {
        sgt.Insert(i + 1, a[i]);
    }
    for (int i = 0; i < a.size(); i++) {
        if (i == 0 && a.size() - 1) {
            answer++;
        }
        else {
            int left = sgt.Search(1, a.size(), 1, 1, i);
            int right = sgt.Search(1, a.size(), 1, i + 2, a.size());
            if (!(left < a[i] && right < a[i])) {
                answer++;
            }
        }
    }
    return answer;
}