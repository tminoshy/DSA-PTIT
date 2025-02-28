//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 01/10/2024

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int C, N;
    cin >> C >> N;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    vector<int> dp(C + 1, 0);
    for (size_t i = 0; i < N; i++) {
        for (size_t j = C; j >= numbers[i]; j--) {
            dp[j] = max(dp[j], dp[j - numbers[i]] + numbers[i]);
        }
    }
    cout << dp[C] << endl;
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//XEM PHIM