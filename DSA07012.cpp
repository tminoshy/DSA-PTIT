//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <stack>

using namespace std;

void Testcase() {
    string s; cin >> s;
    stack<string> mystk;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            string second = mystk.top();
            mystk.pop();
            string first = mystk.top();
            mystk.pop();
            string temp = "(" + first + s[i] + second + ")";
            mystk.push(temp);
        } else {
            mystk.push(string(1, s[i]));
        }
    }
    cout << mystk.top() << endl;
}

int main() {
    int testCount; cin >> testCount;
    cin.ignore();
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//BIẾN ĐỔI HẬU TỐ - TRUNG TỐ