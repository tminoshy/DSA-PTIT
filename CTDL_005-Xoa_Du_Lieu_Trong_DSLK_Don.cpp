//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 14/08/2024

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {};
    Node(int val) : val(val), next(nullptr) {};
    Node(int val, Node *link) : val(val), next(link) {};
};

class Linkedlist {
    public:
        Node *head;
        Linkedlist() : head(nullptr) {};
        void append(int value) {
            if (!head) {
                head = new Node(value);
            } else {
                Node *current = head;
                while (current->next) {
                    current = current->next;
                }
                current->next = new Node(value);
            }
        }
};

void solve() {
    Linkedlist mylist;
    int n; cin >> n;
    for (size_t i = 0; i < n; i++) {
        int element; cin >> element;
        mylist.append(element);
    }
    int target; cin >> target;
    Node *dummyHead = new Node(-1);
    dummyHead->next = mylist.head;
    Node *index = mylist.head;
    Node *current = dummyHead;
    while (index) {
        if (index->val != target) {
            current->next = index;
            current = current->next;
        }
        index = index->next;
    }
    current->next = nullptr;
    while (dummyHead->next) {
        cout << dummyHead->next->val << " ";
        dummyHead = dummyHead->next;
    }
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//XÓA DỮ LIỆU TRONG DSLK ĐƠN