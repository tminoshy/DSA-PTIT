//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 13/10/2024

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void testcase() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, INT_MAX));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> dp[i][j];
        }
    }
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] += min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }

    cout << dp[N][M] << '\n';
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
//ĐƯỜNG ĐI NHỎ NHẤT