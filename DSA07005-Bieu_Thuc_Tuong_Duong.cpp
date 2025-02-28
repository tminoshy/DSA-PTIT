//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 16/10/2024

#include <iostream>
#include <stack>

using namespace std;

void testcase() {
    string s;
    cin >> s;
    stack<char> mystk;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            string temp = "";
            while (!mystk.empty() && mystk.top() != '(') {
                temp = mystk.top() + temp;
                mystk.pop();
            }
            mystk.pop();
            char x = mystk.empty() ? '+' : mystk.top();

            for (int j = 0; j < temp.size(); j++) {
                if (x == '-' && !mystk.empty()) {
                    if (temp[j] == '-') {
                        mystk.push('+');
                    } else if(temp[j] == '+') {
                        mystk.push('-');
                    } else {
                        mystk.push(temp[j]);
                    }
                } else {
                    mystk.push(temp[j]);
                }
            }
        } else {
            mystk.push(s[i]);
        }
    }
    string res = "";
    while (!mystk.empty()) {
        res = mystk.top() + res;
        mystk.pop();
    }

    cout << res << '\n';
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
//BIỂU THỨC TƯƠNG ĐƯƠNG