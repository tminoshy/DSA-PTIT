//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 01/10/2024

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void testcase() {
    int N, V;
    cin >> N >> V;
    vector<pair<int, int>> attribute(N);
    for (size_t i = 0; i < N; i++) {
        cin >> attribute[i].first;
    }
    for (size_t i = 0; i < N; i++) {
        cin >> attribute[i].second;
    }
    vector<int> dp(V + 1, 0);\
    for (int i = 0; i < N; i++) {
        int volume = attribute[i].first;
        int value = attribute[i].second;
        for (int j = V; j >= volume; j--) {
            dp[j] = max(dp[j], dp[j - volume] + value);
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
//CÁI TÚI