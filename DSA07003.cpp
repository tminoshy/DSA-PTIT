//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <stack>

using namespace std;

void Testcase() {
    stack<char> mystk;
    string s; cin >> s;
    for(char x : s) {
        if(x == ')') {
            bool check = false;
            while(mystk.top() != '(') {
                char temp = mystk.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/') {
                    check = true;
                }
                mystk.pop();
            }
            mystk.pop();
            if(!check) {
                cout << "Yes" << endl;
                return;
            }
        } else {
            mystk.push(x);
        }
    }
    cout << "No" << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//KIỂM TRA BIỂU THỨC SỐ HỌC