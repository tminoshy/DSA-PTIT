//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 01/10/2024

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int MOD = 1e9 + 7;

int biomial_coefficient(int n, int k) {
    if (k > n) return 0;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (size_t i = 0; i <= n; i++) {
        for (size_t j = 0; j <= fmin(i, k); j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
    }

    return dp[n][k];
}

void testcase() {
    int n, k;
    cin >> n >> k;
    cout << biomial_coefficient(n, k) << endl;
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
//TỔ HỢP C(n, k)