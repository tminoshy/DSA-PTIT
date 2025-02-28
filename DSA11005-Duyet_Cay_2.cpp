//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 14/10/2024

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Tree {
    int value;
    Tree *left, *right;

    Tree(int number) : value(number), left(nullptr), right(nullptr) {}
};

Tree *buildTreeHelper(int start, int end, const vector<int> &inOrder, const vector<int> &levelOrder, const unordered_map<int, int> &inOrderIdx, unordered_map<int, bool> &visited) {
    if (start > end) {
        return nullptr;
    }
    int rootVal = -1;
    for (int value : levelOrder) {
        if (!visited[value] && inOrderIdx.at(value) >= start && inOrderIdx.at(value) <= end) {
            rootVal = value;
            visited[value] = true;
            break;
        }
    }

    Tree *root = new Tree(rootVal);
    int idx = inOrderIdx.at(rootVal);
    root->left = buildTreeHelper(start, idx - 1, inOrder, levelOrder, inOrderIdx, visited);
    root->right = buildTreeHelper(idx + 1, end, inOrder, levelOrder, inOrderIdx, visited);

    return root;
}

Tree *buildTree(const vector<int> &inOrder, const vector<int> &levelOrder) {
    unordered_map<int, int> inOrderIdx;
    for (int i = 0; i < inOrder.size(); i++) {
        inOrderIdx[inOrder[i]] = i;
    }

    unordered_map<int, bool> visited;
    for (int i = 0; i < inOrder.size(); i++) {
        visited[inOrder[i]] = false;
    }

    return buildTreeHelper(0, inOrder.size() - 1, inOrder, levelOrder, inOrderIdx, visited);
}

void postOrderTraversal(Tree *&root) {
    if (root == nullptr) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->value << " ";
}

void testcase() {
    int N;
    cin >> N;
    
    vector<int> inOrder(N);
    for (int &value : inOrder) {
        cin >> value;
    }

    vector<int> levelOrder(N);
    for (int &value : levelOrder) {
        cin >> value;
    }

    Tree *root = buildTree(inOrder, levelOrder);
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
//DUYỆT CÂY 2