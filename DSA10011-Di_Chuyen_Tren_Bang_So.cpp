//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 28/10/2024

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>

using namespace std;

//Fear is just an illusion

int findShortestPath(int N, int M, const vector<vector<int>>& grid) {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    vector<vector<int>> dp(N, vector<int>(M, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({grid[0][0], 0, 0});

    while (!pq.empty()) {
        auto [cost, row, col] = pq.top();
        pq.pop();

        if (row == N - 1 && col == M - 1) {
            return cost;
        }

        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M) {
                int newCost = cost + grid[newRow][newCol];
                if (newCost < dp[newRow][newCol]) {
                    dp[newRow][newCol] = newCost;
                    pq.emplace(newCost, newRow, newCol);
                }
            }
        }
    }

    return -1;
}

void testcase() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    cout << findShortestPath(N, M, grid) << '\n';
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
//DI CHUYỂN TRÊN BẢNG SỐ