//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 15/10/2024

#include <iostream>
#include <vector>

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

void postOrderTraversal(Tree *&root) {
    if (!root) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    cout << root->value << " ";
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

    postOrderTraversal(root);
    
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
//DUYỆT CÂY NHỊ PHÂN TÌM KIẾM 2