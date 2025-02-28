//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 15/10/2024

#include <iostream>

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

bool isLeaf(Tree *&root) {
    return !root->left && !root->right;
}

void findLeaf(Tree *&root) {
    if (!root) return;
    if (isLeaf(root)) {
        cout << root->value << " ";
    }
    findLeaf(root->left);
    findLeaf(root->right);
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
    findLeaf(root);
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
//NODE LÁ CỦA CÂY NHỊ PHÂN TÌM KIẾM