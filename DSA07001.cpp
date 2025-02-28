//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void solve() {
    string s;
    stack<string> myStack;
    while(cin >> s) {
        if(s == "push") {
            cin >> s;
            myStack.push(s);
        }
        else if(s == "pop") {
            myStack.pop();
        }
        else if(s == "show") {
            if(myStack.empty()) {
                cout << "empty" << endl;
            } else {
                vector<string> storage;
                while(!myStack.empty()) {
                    string element = myStack.top();
                    storage.push_back(element);
                    myStack.pop();
                }
                for(int i = storage.size() - 1; i >= 0; i--) {
                    cout << storage[i] << " ";
                    myStack.push(storage[i]);
                }
                cout << endl;
            }
        }
    }
}

int main() {
    solve();
    return 0;
}

//NGĂN XẾP 1