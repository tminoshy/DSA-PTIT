//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Fear is just an illusion

void testcase() {
    long long N;
    cin >> N;

    int len = static_cast<int>(log10(N)) + 1;
    vector<vector<long long>> dp(len, vector<long long>(len));
    
    long long sum = 0;
    for (int i = len - 1; i >= 0; i--) {
        dp[0][i] = N % 10;
        N /= 10;
        sum += dp[0][i];
    }

    for (int i = 1; i < len; i++) {
        for (int j = i; j < len; j++) {
            dp[i][j] = dp[i - 1][j - 1] * 10 + dp[0][j];
            sum += dp[i][j];
        }
    }

    cout << sum << '\n';
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
//TỔNG CÁC XÂU CON