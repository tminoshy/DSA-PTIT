//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void Testcase() {
    string s; cin >> s;
    stack<string> mystk;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            int second = stoi(mystk.top());
            mystk.pop();
            int first = stoi(mystk.top());
            mystk.pop();
            if(s[i] == '+') {
                mystk.push(to_string(first + second));
            } else if(s[i] == '-') {
                mystk.push(to_string(first - second));
            } else if(s[i] == '*') {
                mystk.push(to_string(first * second));
            } else if(s[i] == '/') {
                mystk.push(to_string(first / second));
            }
        } else {
            mystk.push(string(1, s[i]));
        }
    }
    cout << mystk.top() << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//TÍNH GIÁ TRỊ BIỂU THỨC HẬU TỐ

//231*+9–  -2
//2(3*1)+9-
//(2+(3*1))9-
//(2+(3*1))-9