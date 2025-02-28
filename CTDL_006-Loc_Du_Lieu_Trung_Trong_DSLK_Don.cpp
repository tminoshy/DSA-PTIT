//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 14/08/2024

#include <iostream>
#include <map>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {};
    Node(int value) : val(value), next(nullptr) {};
    Node(int value, Node *link) : val(value), next(link) {};
};

class Linkedlist {
    public:
        Node *head;
        Linkedlist() : head(nullptr) {};

        void append(int number) {
            if (!head) {
                head = new Node(number);
            } else {
                Node *current = head;
                while (current->next) {
                    current = current->next;
                }
                current->next = new Node(number);
            }
        }
};

void solve() {
    int n; cin >> n;
    Linkedlist myList;
    map<int, int> confirm;
    for(size_t i = 0; i < n; i++) {
        int element; cin >> element;
        myList.append(element);
    }
    Node *dummyHead = new Node(-1);
    dummyHead->next = myList.head;
    Node *current = dummyHead;
    Node *index = myList.head;
    while (index) {
        if (confirm[index->val] == 0) {
            confirm[index->val]++;
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
//LỌC DỮ LIỆU TRÙNG TRONG DSLK ĐƠN