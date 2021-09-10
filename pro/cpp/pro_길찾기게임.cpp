#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
struct Node {
    int x, y, idx;
    Node* left;
    Node* right;
    Node() {
        left = NULL;
        right = NULL;
    }
};
class Tree {
public:
    Node* root;
    vector<int> pre;
    vector<int> post;
    Tree() {
        root = NULL;
    }
    void InsertNode(Node* n) {
        if (root == NULL) {
            root = n;
            return;
        }
        Node* pos = root;
        while (1) {
            if (pos->x > n->x) {
                if (pos->left == NULL) {
                    pos->left = n;
                    return;
                }
                else {
                    pos = pos->left;
                }
            }
            else {
                if (pos->right == NULL) {
                    pos->right = n;
                    return;
                }
                else {
                    pos = pos->right;
                }
            }
        }
    }
    void DFS() {
        pre.clear();
        post.clear();
        DFS(root);
    }
    void DFS(Node* n) {
        pre.push_back(n->idx);
        if (n->left != NULL) {
            DFS(n->left);
        }
        if (n->right != NULL) {
            DFS(n->right);
        }
        post.push_back(n->idx);
    }
};
bool CompPosY(const Node& n1, const Node& n2);
int N;
Node node[10000], * root;
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    N = nodeinfo.size();
    for (int i = 0; i < N; i++) {
        node[i].x = nodeinfo[i][0];
        node[i].y = nodeinfo[i][1];
        node[i].idx = i + 1;

    }
    sort(node, node + N, CompPosY);
    Tree tree;
    for (int i = 0; i < N; i++) {
        tree.InsertNode(&node[i]);
    }
    tree.DFS();
    answer.push_back(tree.pre);
    answer.push_back(tree.post);

    return answer;
}
bool CompPosY(const Node& n1, const Node& n2) {

    return n1.y > n2.y;
}