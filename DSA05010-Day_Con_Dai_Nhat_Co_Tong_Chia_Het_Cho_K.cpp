//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 1/11/2024

#include <iostream>
#include <vector>

using namespace std;

//Fear is just an illusion

void testcase() {
    int N, K;
    cin >> N >> K;

    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }

    vector<int> dp(K, -1);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        vector<int> newDp = dp;
        for (int j = 0; j < K; j++) {
            if (dp[j] >= 0) {
                int reminder = (j + numbers[i]) % K;
                newDp[reminder] = max(newDp[reminder], dp[j] + 1);
            }
        }
        dp = newDp;
    }
    
    cout << dp[0] << '\n';
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
//DÃY CON DÀI NHẤT CÓ TỔNG CHIA HẾT CHO K