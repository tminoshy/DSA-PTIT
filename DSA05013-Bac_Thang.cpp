//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 01/10/2024

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

void testcase() {
    int N, K;
    cin >> N >> K;
    vector<long long> dp(N + 1, 0);
    dp[0] = 1;
    long long current = dp[0];
    for (int i = 1; i <= N; i++) {
        dp[i] = current;
        if (i < K) {
            current = (current + dp[i]) % MOD;
        } else {
            current = (current + dp[i] - dp[i - K] + MOD) % MOD;
        }
    }
    cout << dp[N] << endl;
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
//BẬC THANG