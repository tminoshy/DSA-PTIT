//https://github.com/tminoshy
//created by Đỗ Thiện Minhin 15/10/2024

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Tree {
    int value;
    Tree *left, *right;

    Tree(int number) : value(number), left(nullptr), right(nullptr) {}
};

Tree *BST(int start, int end, const vector<int>& nodeVal) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;
    Tree *root = new Tree(nodeVal[mid]);

    root->left = BST(start, mid - 1, nodeVal);
    root->right = BST(mid + 1, end, nodeVal);

    return root;
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
    
    vector<int> nodeVal(N);
    for (int &value : nodeVal) {
        cin >> value;
    }
    
    sort(nodeVal.begin(), nodeVal.end());
    Tree *root = BST(0, N - 1, nodeVal);
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
//DUYỆT SAU CÂY TÌM KIẾM CÂN BẰNG