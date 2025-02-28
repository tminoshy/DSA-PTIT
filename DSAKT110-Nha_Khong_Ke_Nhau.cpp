//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 04/10/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    vector<int> dp(N);
    if (N == 1) {
        cout << dp[0] << endl;
        return;
    }
    dp[0] = numbers[0];
    dp[1] = max(numbers[0], numbers[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = max(dp[i - 1], numbers[i] + dp[i - 2]);
    }
    cout << dp[N - 1] << endl;
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
//NHÀ KHÔNG KỀ NHAU