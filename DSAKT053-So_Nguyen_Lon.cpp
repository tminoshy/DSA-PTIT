//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 04/10/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    string S1, S2;
    cin >> S1 >> S2;
    int N = S1.size();
    int M = S2.size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[N][M] << endl;

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
//SỐ NGUYÊN LỚN