//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 17/10/2024

#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

//Fear is just an illusion

void testcase() {
    string s;
    cin >> s;
    stack<char> mystk;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ']') {
            string temp = "";
            while (!mystk.empty() && mystk.top() != '[') {
                temp = mystk.top() + temp;
                mystk.pop();
            }
            mystk.pop();
            string number = "";
            while (!mystk.empty() && isdigit(mystk.top())) {
                number = mystk.top() + number;
                mystk.pop();
            }
            int numb = 1;
            if (number.size()) {
                numb = stoi(number);
            }
            string expanded = "";
            for (int j = 0; j < numb; j++) {
                expanded += temp;
            }
            for (int j = 0; j < expanded.size(); j++) {
                mystk.push(expanded[j]);
            }
        } else {
            mystk.push(s[i]);
        }
    }

    string ans = "";
    while (!mystk.empty()) {
        ans = mystk.top() + ans;
        mystk.pop();
    }

    cout << ans << '\n';
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
//GIẢI MÃ XÂU KÝ TỰ