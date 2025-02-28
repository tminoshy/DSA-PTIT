//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <stack>

using namespace std;
//*+AB-CD stk : 
//CD
//(C+D)
//(C+D)AB
//(C+D)(A+B)
//((C+D)*(A+D))
void Testcase() {
    string s; cin >> s;
    stack<string> mystk;
    for(char x : s) {
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                string first = mystk.top();
                mystk.pop();
                string second = mystk.top();
                mystk.pop();
                string temp = '(' + first + s[i] + second + ')';
                mystk.push(temp);
            } else {
                mystk.push(string(1, s[i]));
            }
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

//BIẾN ĐỔI TIỀN TỐ - TRUNG TỐ