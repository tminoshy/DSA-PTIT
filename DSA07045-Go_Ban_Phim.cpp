//https://github.com/tminoshy
//created by Đỗ Thiện Minh on 4/11/2024

#include <iostream>
#include <stack>

using namespace std;

//Fear is just an illusion

void solve() {
    string s;
    cin >> s;
    stack<char> mystk;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '<') {
            if (!ans.empty()) {
                mystk.push(ans.back());
                ans.pop_back();
            }
        } else if (s[i] == '>') {
            if (!mystk.empty()) {
                ans.push_back(mystk.top());
                mystk.pop();
            }
        } else if (s[i] == '-') {
            if (!ans.empty()) {
                ans.pop_back();
            }
        } else {
            ans.push_back(s[i]);
        }
    }

    while (!mystk.empty()) {
        ans.push_back(mystk.top());
        mystk.pop();
    }

    cout << ans << '\n';
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//GÕ BÀN PHÍM