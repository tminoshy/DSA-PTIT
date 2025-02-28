//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 14/09/2024

#include <iostream>
#include <string>

using namespace std;

void Testcase() {
    string brackets; cin >> brackets;
    int count = 0;
    while (brackets.size()) {
        size_t index = brackets.find("()");
        if (index != string::npos) {
            brackets.erase(index, 2);
        } else {
            if (brackets[0] == ')') {
                count++;
                brackets[0] = '(';
            } else if (brackets.back() == '(') {
                count++;
                brackets.back() = ')';
            }
        }
    }
    cout << count << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//