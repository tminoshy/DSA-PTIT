//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 11/10/2024

#include <iostream>

using namespace std;

void testcase() {
    string S;
    cin >> S;
    int open = 0;
    int ans = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') {
            open++;
        } else {
            if (open > 0) {
                open--;
                ans += 2;
            }
        }
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
//BIỂU THỨC ĐÚNG DÀI NHẤT