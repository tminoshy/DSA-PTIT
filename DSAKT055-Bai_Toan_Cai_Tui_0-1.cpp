//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 04/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase() {
    int N, V;
    cin >> N >> V;
    vector<pair<int, int>> attribute(N);
    for (int i = 0; i < N; i++) {
        cin >> attribute[i].first;
    }
    for (int i = 0; i < N; i++) {
        cin >> attribute[i].second;
    }
    vector<int> dp(V + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int j = V; j >= attribute[i].first; j--) {
            dp[j] = max(dp[j], dp[j - attribute[i].first] + attribute[i].second);
        }
    }
    cout << dp[V] << endl;
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
//BÀI TOÁN CÁI TÚI 0-1