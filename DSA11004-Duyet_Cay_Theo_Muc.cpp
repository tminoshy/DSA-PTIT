//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 13/10/2024

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int value;
    Node *left, *right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

void addNode(int parent, int child, char LorR, Node *&root) {
    if (root == nullptr) {
        root = new Node(parent);
        if (LorR == 'L') {
            root->left = new Node(child);
        } else if (LorR == 'R') {
            root->right = new Node(child);
        }
    } else {
        if (root->value == parent) {
            if (LorR == 'L') {
                root->left = new Node(child);
            } else if (LorR == 'R') {
                root->right = new Node(child);
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
}

void levelOrderTraversal(Node *root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *current = q.front();
        q.pop();
        cout << current->value << " ";
        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

void testcase() {
    int N;
    cin >> N;
    Node *root = nullptr;
    for (int i = 0; i < N; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        addNode(u, v, c, root);
    }
    levelOrderTraversal(root);
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
//DUYỆT CÂY THEO MỨC