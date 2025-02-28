//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 15/10/2024

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

struct Tree {
    int value;
    Tree *left, *right;

    Tree(int number) : value(number), left(nullptr), right(nullptr) {}
};

void addNode(int parent, int child, int LorR, Tree *&root, unordered_map<int, Tree *> &umap)  {
    if (umap.find(parent) == umap.end()) {
        root = new Tree(parent);
        umap[parent] = root;
        if (LorR == 'L') {
            root->left = new Tree(child);
            umap[child] = root->left;
        } else if (LorR == 'R') {
            root->right = new Tree(child);
            umap[child] = root->right;
        }
    } else {
        if (LorR == 'L') {
            umap[parent]->left = new Tree(child);
            umap[child] = umap[parent]->left;
        } else if (LorR == 'R') {
            umap[parent]->right = new Tree(child);
            umap[child] = umap[parent]->right;
        }
    }
}

void zigzagTraversal(Tree *&root) {
    if (!root) return;

    bool leftToRight = false;
    stack<Tree *> current;
    stack<Tree *> nextLevel;
    current.push(root);

    while(!current.empty()) {
        Tree *node = current.top();
        current.pop();

        if (node) {
            cout << node->value << " ";

            if (leftToRight) {
                if (node->left) nextLevel.push(node->left);
                if (node->right) nextLevel.push(node->right);    
            } else {
                if (node->right) nextLevel.push(node->right);
                if (node->left) nextLevel.push(node->left);
            }
        }
        if (current.empty()) {
            leftToRight = !leftToRight;
            swap(current, nextLevel);
        }
    }
}


void testcase() {
    int N;
    cin >> N;
    unordered_map<int, Tree *> umap;
    Tree *root = nullptr;

    for (int i = 0; i < N; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        addNode(u, v, c, root, umap);
    }

    zigzagTraversal(root);
    
    cout << '\n';
}

int main() {
    int testCaseCount;
    cin >> testCaseCount;

    while (testCaseCount--) {
        testcase();

    }
    return 0;
}

//B23DCCE064
//DUYỆT CÂY KIỂU XOẮN ỐC