//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/10/2024

#include <iostream>
#include <vector>

using namespace std;

//Fear is just an illusion

const int MOD = 1e9 + 7;

void testcase() {
    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(10, 0));
    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = j; k <= 9; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD; 
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[N][i]) % MOD;
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
//CHỮ SỐ SẮP XẾP TĂNG DẦN