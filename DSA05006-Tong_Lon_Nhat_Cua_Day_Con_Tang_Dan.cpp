//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 07/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    vector<int> dp(N, 0);
    for (int i = 0; i < N; i++) {
        dp[i] = numbers[i];
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (numbers[i] > numbers[j] && dp[i] < dp[j] + numbers[i]) {
                dp[i] = dp[j] + numbers[i];
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
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
//TỔNG LỚN NHẤT CỦA DÃY CON TĂNG DẦN