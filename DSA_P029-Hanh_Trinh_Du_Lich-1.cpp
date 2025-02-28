//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void testcase() {
    int N; 
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    vector<vector<int>> dp(1 << N, vector<int>(N, INT_MAX));
    for (int i = 0; i < N; i++) {
        dp[1 << i][i] = 0;
    }

    for (int mask = 1; mask < (1 << N); mask++) {
        for (int u = 0; u < N; u++) {
            if ((mask & (1 << u)) == 0) continue;
            for (int v = 0; v < N; v++) {
                if (mask & (1 << v)) continue;
                dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + graph[u][v]);
            }
        }
    }
    cout << *min_element(dp[(1 << N) - 1].begin(), dp[(1 << N) - 1].end()) << endl;
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
//HÀNH TRÌNH DU LỊCH - 1