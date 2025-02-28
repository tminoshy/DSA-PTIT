//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 07/10/2024

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

void testcase() {
    int n, k;
    cin >> n >> k;
    // Dynamic programming
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0) {
                dp[i][j] = 1; // Base case: P(n, 0) = 1
            } else if (i == 0) {
                dp[i][j] = 0; // Base case: P(0, k) = 0 for k > 0
            } else {
                //P(n, k) = P(n - 1, k) + k * P(n - 1, k - 1)
                dp[i][j] = (dp[i - 1][j] + (j * dp[i - 1][j - 1]) % MOD) % MOD;
            }
        }
    }
    cout << dp[n][k] << endl;
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
//TÍNH P(N,K)