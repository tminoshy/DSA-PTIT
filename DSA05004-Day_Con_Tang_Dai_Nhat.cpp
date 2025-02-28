//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 01/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLongestIncreaseSequence(int N, const vector<int>& numbers) {
    vector<int> dp(N, 1);
    for (size_t i = 1; i < N; i++) {
        for (size_t j = 0; j < i; j++) {
            if (numbers[j] < numbers[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

void solve() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    cout << findLongestIncreaseSequence(N, numbers) << endl;
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//DÃY CON TĂNG DÀI NHẤT