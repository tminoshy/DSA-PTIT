//https://github.com/tminoshy
//created by Đỗ Thiện Minh at 16/09/2024

#include <iostream>
#include <stack>

using namespace std;

//((()
//[-1 0 1 ]
// )()())
//[5]
// ()(()))))

void Testcase() {
    string s; cin >> s;
    stack<int> mystk;
    mystk.push(-1);
    int maxLength = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            mystk.push(i);
        } else if(s[i] == ')') {
            mystk.pop();
            if(mystk.empty()) {
                mystk.push(i);
            }
            maxLength = (i - mystk.top() > maxLength) ? (i - mystk.top()) : maxLength;
        }
    }
    cout << maxLength << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//DÃY NGOẶC ĐÚNG DÀI NHẤT