//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 04/10/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int M, N, K;
    cin >> M >> N >> K;
    string X, Y, Z;
    cin >> X >> Y >> Z;
    vector<vector<vector<int>>> dp(M + 1, vector<vector<int>>(N + 1, vector<int>(K + 1, 0)));
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= K; k++) {
                if (X[i - 1] == Y[j - 1] && Y[j - 1] == Z[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else {
                    dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
                }
            }
        }
    }
    cout << dp[M][N][K] << endl;
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
//DÃY CON CHUNG DÀI NHẤT CỦA BA XÂU