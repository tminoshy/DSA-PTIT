//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <stack>

using namespace std;

void Testcase() {
    string s; cin >> s;
    stack<char> check;
    for(char c : s) {
        if(c == '[' || c == '{' || c == '(') {
            check.push(c);
        } else {
            if(check.empty()) {
                cout << "NO" << endl;
                return;
            } else {
                if(c == ']' && check.top() == '[') {
                    check.pop();
                } else if(c == '}' && check.top() == '{') {
                    check.pop();
                } else if(c == ')' && check.top() == '(') {
                    check.pop();
                }
            }
        }
    }
    if(check.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//