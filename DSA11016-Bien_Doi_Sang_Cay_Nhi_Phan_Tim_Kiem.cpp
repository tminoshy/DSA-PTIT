//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 15/10/2024

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

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

void getVal(Tree *root, vector<int> &nodeVal) {
    if (!root) return;

    nodeVal.push_back(root->value);
    getVal(root->left, nodeVal);
    getVal(root->right, nodeVal);
}

void fillVal(int &index, Tree *root, const vector<int> &nodeVal) {
    if (!root) return;

    fillVal(index, root->left, nodeVal);
    root->value = nodeVal[index++];
    fillVal(index, root->right, nodeVal);
}

void inOrderTraversal(Tree *root) {
    if (!root) return;

    inOrderTraversal(root->left);
    cout << root->value << " ";
    inOrderTraversal(root->right);
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
    
    vector<int> nodeVal;
    getVal(root, nodeVal);
    sort(nodeVal.begin(), nodeVal.end());
    int index = 0;
    fillVal(index, root, nodeVal);
    inOrderTraversal(root);
    
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
//BIẾN ĐỔI SANG CÂY NHỊ PHÂN TÌM KIẾM