//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <stack>

//AB+CD-*
//(+AB)(-CD)

using namespace std;

//AB-
//+AB
void Testcase() {
    string s; cin >> s;
    stack<string> mystk;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            string second = mystk.top();
            mystk.pop();
            string first = mystk.top();
            mystk.pop();
            string temp = s[i] + first + second;
            mystk.push(temp);
        } else {
            mystk.push(string(1, s[i]));
        }
    }
    cout << mystk.top() << endl;
}

/*void Testcase() {
    string s; cin >> s;
    stack<string> mystk;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            string second = mystk.top();
            mystk.pop();
            string first = mystk.top();
            mystk.pop();
            string temp = s[i] + first + second;
            mystk.push(temp);
        } else {
            mystk.push(string(1, s[i]));
        }
    }
    cout << mystk.top() << endl;
}*/

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//BIẾN ĐỔI HẬU TỐ - TIỀN TỐ