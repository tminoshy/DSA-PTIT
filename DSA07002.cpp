//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

void solve() {
    int n; cin >> n;
    stack<string> mystk;
    while(n--) {
        string s; cin >> s;
        if(s[1] == 'U') {
           cin >> s;
           mystk.push(s);
        } else if(s[1] == 'O') {
            if(!mystk.empty()) {
                mystk.pop();
            }
        } else if(s[1] == 'R') {
            if(mystk.empty()) {
                cout << "NONE" << endl;
                continue;
            }
            cout << mystk.top() << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}

//NGĂN XẾP 2