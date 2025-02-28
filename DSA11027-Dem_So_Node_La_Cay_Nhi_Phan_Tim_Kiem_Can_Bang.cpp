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

bool isLeaf(Tree *&root) {
    return !root->left && !root->right;
}

void countLeaf(Tree *&root, int &count) {
    if (!root) return;

    if (isLeaf(root)) {
        count++;
    }

    countLeaf(root->left, count);
    countLeaf(root->right, count);
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
    int count = 0;
    countLeaf(root, count);

    cout << count;
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
//ĐẾM SỐ NODE LÁ CÂY NHỊ PHÂN TÌM KIẾM CÂN BẰNG