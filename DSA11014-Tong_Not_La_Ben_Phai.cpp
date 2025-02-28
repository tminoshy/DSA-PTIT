//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 14/10/2024

#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;

struct Tree {
    int value;
    Tree *left, *right;

    Tree(int number) : value(number), left(nullptr), right(nullptr) {}
};

void addNode(int parent, int child, char LorR, Tree *&root, unordered_map<int, Tree *> &umap) {
    if (umap.find(parent) == umap.end()) {
        root = new Tree(parent);
        umap[parent] = root;

        if (LorR == 'L') {
            root->left = new Tree(child);
            umap[child] = root->left;
        } else {
            root->right = new Tree(child);
            umap[child] = root->right;
        }
    } else {
        if (LorR == 'L') {
            umap[parent]->left = new Tree(child);
            umap[child] = umap[parent]->left;
        } else {
            umap[parent]->right = new Tree(child);
            umap[child] = umap[parent]->right;
        }
    }
}

int sumLeafRight(Tree *&root) {
    if (root == nullptr) {
        return 0;
    }
    
    queue<tuple<Tree *, int, char>> q;
    q.push({root, 0, 'M'});
    int sumR = 0;
    while (!q.empty()) {
        auto [root, level, LorR] = q.front();
        q.pop();
        if (root->left == nullptr && root->right == nullptr) {
            if (LorR == 'R') {
                sumR += root->value;
            }
        }
        if (root->left != nullptr) {
            q.push({root->left, level + 1, 'L'});
        }
        if (root->right != nullptr) {
            q.push({root->right, level + 1, 'R'});
        }
    }
    return sumR;
}

void testcase() {
    int N;
    cin >> N;

    Tree *root = nullptr;
    unordered_map<int, Tree *> umap;

    for (int i = 0; i < N; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        addNode(u, v, c, root, umap);
    }

    cout << sumLeafRight(root) << '\n';
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
//TỔNG NODE LÁ BÊN PHẢI