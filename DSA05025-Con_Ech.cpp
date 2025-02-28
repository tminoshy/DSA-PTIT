//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 01/10/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int n; cin >> n;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    long long current = dp[0];
    for (int i = 1; i <= n; i++) {
        dp[i] = current;
        if (i < 3) {
            current += dp[i];
        } else {
            current += (dp[i] - dp[i - 3]);
        }
    }
    cout << dp[n] << endl;
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
//CON ẾCH