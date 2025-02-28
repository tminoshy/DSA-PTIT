//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 06/10/2024

#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

void testcase() {
    string P; cin >> P;
    stack<string> mystk;
    for (int i = 0; i < P.size(); i++) {
        if (isalpha(P[i])) {
            mystk.push(string(1, P[i]));
        } else {
            string second = mystk.top();
            mystk.pop();
            string first = mystk.top();
            mystk.pop();
            mystk.push(first + P[i] + second);
        }
    }
    cout << mystk.top() << endl;
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
//CÂY BIỂU THỨC 1