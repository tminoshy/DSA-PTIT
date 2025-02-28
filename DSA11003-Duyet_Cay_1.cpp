//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 13/10/2024

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Tree {
    int value;
    Tree *left, *right;

    Tree(int number) : value(number), left(nullptr), right(nullptr) {}
};

void postOrder(Tree* root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->value << " ";
}



Tree* buildTreeHelper(int &preIdx, int start, int stop, const vector<int> &inordered, const vector<int> &preorder, unordered_map<int, int> &inorderedIdx) {
    if (start > stop) {
        return nullptr;
    }
    int Nodeval = preorder[preIdx++];
    Tree* Node = new Tree(Nodeval);
    int index = inorderedIdx[Nodeval];
    Node->left = buildTreeHelper(preIdx, start, index - 1, inordered, preorder, inorderedIdx);
    Node->right = buildTreeHelper(preIdx, index + 1, stop, inordered, preorder, inorderedIdx);

    return Node;
}

Tree* buildTree(const vector<int> &inordered, const vector<int> &preorder) {
    unordered_map<int, int> inorderedIdx;
    for (int i = 0; i < inordered.size(); i++) {
        inorderedIdx[inordered[i]] = i;
    }
    int preIdx = 0;

    return buildTreeHelper(preIdx, 0, preorder.size() - 1, inordered, preorder, inorderedIdx);
    
}

void testcase() {
    int N;
    cin >> N;

    vector<int> inorder(N);
    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }

    vector<int> preorder(N);
    for (int i = 0; i < N; i++) {
        cin >> preorder[i];
    }
    Tree* root = buildTree(inorder, preorder);
    postOrder(root);
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
//DUYỆT CÂY 1