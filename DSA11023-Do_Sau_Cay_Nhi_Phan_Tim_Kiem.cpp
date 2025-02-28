//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 15/10/2024

#include <iostream>
#include <queue>

using namespace std;

struct Tree {
    int value;
    Tree *right, *left;

    Tree(int number) : value(number), right(nullptr), left(nullptr) {}
};

void addNode(int nodeVal, Tree *&root) {
    if (!root) {
        root = new Tree(nodeVal);
    } else {
        if (nodeVal > root->value) {
            addNode(nodeVal, root->right);
        } else if (nodeVal < root->value) {
            addNode(nodeVal, root->left);
        }
    }
}

int findDepth(Tree *&root) {
    queue<pair<Tree *, int>> q;
    int leafLevel = 0;
    
    q.push({root, 0});
    while (!q.empty()) {
        auto [root, currentLevel] = q.front();
        q.pop();
        if (!root->left && !root->right) {
            leafLevel = max(leafLevel, currentLevel);
        }
        if (root->left) q.push({root->left, currentLevel + 1});
        if (root->right) q.push({root->right, currentLevel + 1});
    }

    return leafLevel;
}

void testcase() {
    int N;
    cin >> N;
    Tree *root = nullptr;

    for (int i = 0; i < N; i++) {
        int nodeVal;
        cin >> nodeVal;
        addNode(nodeVal, root);
    }

    cout << findDepth(root);

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
//ĐỘ SÂU CÂY NHỊ PHÂN TÌM KIẾM