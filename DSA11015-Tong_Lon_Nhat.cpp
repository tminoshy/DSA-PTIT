//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 22/10/2024

#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

//Fear is just an illusion

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void addNode(Node*& root, int u, int v, char c) {
    if (!root) {
        root = new Node(u);
        if (c == 'L') root->left = new Node(v);
        else root->right = new Node(v);
    } else {
        if (root->data == u) {
            if (c == 'L') root->left = new Node(v);
            else root->right = new Node(v);
        } else {
            if (root->left) addNode(root->left, u, v, c);
            if (root->right) addNode(root->right, u, v, c);
        }
    }
}

int maxPathSumUtil(Node* root, int& res) {
    if (!root) return 0;

    int leftSum = maxPathSumUtil(root->left, res);
    int rightSum = maxPathSumUtil(root->right, res);

    if (!root->left && !root->right) return root->data;
    if (!root->left) return rightSum + root->data;
    if (!root->right) return leftSum + root->data;

    res = max(res, leftSum + rightSum + root->data);
    return max(leftSum, rightSum) + root->data;
}

int maxPathSum(Node* root) {
    int res = INT_MIN;
    maxPathSumUtil(root, res);
    return res;
}


void testcase() {
    int N;
    cin >> N;

    unordered_map<int, Node *> umap;
    Node *root = nullptr;
    for (int i = 0; i < N; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        addNode(root, u, v, c);
    }
    cout << maxPathSum(root) << '\n';
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
//TỔNG LỚN NHẤT