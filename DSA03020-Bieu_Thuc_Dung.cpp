//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 07/10/2024

#include <iostream>
#include <algorithm>

using namespace std;

void testcase() {
    string S; cin >> S;
    int ans = 0;
    int open = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '[') {
            open++;
        } else {
            open--;
        }
        if (open < 0) {
            for (int j = i + 1; j < S.size(); j++) {
                if (S[j] == '[') {
                    ans += (j - i);
                    swap(S[i], S[j]);
                    open = 1;
                    break;
                }
            }
        }   
    }
    cout << ans << endl;
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
//BIỂU THỨC ĐÚNG