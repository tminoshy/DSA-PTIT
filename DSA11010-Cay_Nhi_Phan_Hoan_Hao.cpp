//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 14/10/2024

#include <iostream>
#include <queue>

using namespace std;

struct Tree {
    int value;
    Tree *left, *right;

    Tree(int number) : value(number), left(nullptr), right(nullptr) {}
};

void addNode(int parent, int child, char LorR, Tree *&root) {
    if (root == nullptr) {
        root = new Tree(parent);
    }
    if (root->value == parent) {
        if (LorR == 'L') {
            root->left = new Tree(child);
        } else if (LorR == 'R') {
            root->right = new Tree(child);
        }
    } else {
        if (root->left != nullptr) {
            addNode(parent, child, LorR, root->left);
        } 
        if (root->right != nullptr) {
            addNode(parent, child, LorR, root->right);
        }
    }
}

bool checkLeafLevel(Tree *&root) {
    if (root == nullptr) {
        return false;
    }
    int leafLevel = -1;
    queue<pair<Tree *, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [root, level] = q.front();
        q.pop();
        if (root->left == nullptr || root->right == nullptr) {
            if (root->left == nullptr && root->right != nullptr) {
                return false;
            }
            if (root->left != nullptr && root->right == nullptr) {
                return false;
            }
            if (root->left == nullptr && root->right == nullptr) {
                if (leafLevel == -1) {
                    leafLevel = level;
                } else {
                    if (leafLevel != level) {
                        return false;
                    }
                }
            }
        }
        if (root->left != nullptr) {
            q.push({root->left, level + 1});
        }
        if (root->right != nullptr) {
            q.push({root->right, level + 1});
        }
    }
    return true;
}

void testcase() {
    int N;
    cin >> N;

    Tree *root = nullptr;

    for (int i = 0; i < N; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        addNode(u, v, c, root);
    }
    if (checkLeafLevel(root)) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
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
//CÂY NHỊ PHÂN HOÀN HẢO