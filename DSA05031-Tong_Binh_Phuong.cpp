//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 31/10/2024

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//Fear is just an illusion

void testcase() {
    int N;
    cin >> N;

    vector<int> dp(N + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i * i <= N; i++) {
        int square = i * i;
        for (int j = square; j <= N; j++) {
            dp[j] = min(dp[j], dp[j - square] + 1);
        }
    }

    cout << dp[N] << '\n';
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
//TỔNG BÌNH PHƯƠNG