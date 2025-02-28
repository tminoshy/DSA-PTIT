//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 01/10/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    string M; cin >> M;
    vector<int> dp(M.size() + 1, 0);
    dp[0] = 1;
    dp[1] = (M[0] == '0') ? 0 : 1;
    for (int i = 2; i <= M.size(); i++) {
        if (M[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }
        int digit = stoi(M.substr(i - 2, 2));
        if (digit >= 10 && digit <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    cout << dp[M.size()] << endl;
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
//GIẢI MÃ