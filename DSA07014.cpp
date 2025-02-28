//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <stack>

using namespace std;

void Testcase() {
    string s; cin >> s;
    stack<string> mystk;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            int first = stoi(mystk.top());
            mystk.pop();
            int second = stoi(mystk.top());
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

//TÍNH GIÁ TRỊ BIỂU THỨC TIỀN TỐ
//-+8/632
//23
//236
//2(6/3)
//2(6/3)8
//2(8+(6/3))
