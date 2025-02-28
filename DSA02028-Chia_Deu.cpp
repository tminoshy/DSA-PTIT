//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/10/2024

#include <iostream>
#include <vector>

using namespace std;

//Fear is just an illusion

void canPartition(int& ans, int index, int N, int K, int count, int currentSum, int targetSum, const vector<int>& numbers) {
    if (index == N && count == K) {
        ans++;
        return;
    }
    for (int i = index; i < N; i++) {
        currentSum += numbers[i];
        if (currentSum == targetSum) {
            canPartition(ans, i + 1, N, K, count + 1, 0, targetSum, numbers);
        }
    }
}

void solve() {
    int N, K;
    cin >> N >> K;

    vector<int> numbers(N);
    int totalSum = 0;
    for (int& value : numbers) {
        cin >> value;
        totalSum += value;
    }

    if (totalSum % K != 0) {
        cout << "0";
        return;
    }
    int ans = 0;
    canPartition(ans, 0, N, K, 0, 0, totalSum / K, numbers);

    cout << ans;

}

int main() {
    solve();
}

//B23DCCE064
//CHIA ĐỀU