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
            string first = mystk.top();
            mystk.pop();
            string second = mystk.top();
            mystk.pop();
            string temp = first + second + s[i];
            mystk.push(temp);
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

//

/*
*+AB-CD
(A+B)*(C-D)

*/