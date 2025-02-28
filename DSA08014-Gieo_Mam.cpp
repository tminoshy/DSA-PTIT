//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/10/2024

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

//Fear is just an illusion

void bfs(queue<tuple<int, int, int>>& q, vector<vector<int>>& days, const vector<vector<int>>& grid, int R, int C) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!q.empty()) {
        auto [row, col, day] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            int nextDay = day + 1;

            if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C && grid[newRow][newCol] == 1 && (days[newRow][newCol] == -1 || days[newRow][newCol] > nextDay)) {
                days[newRow][newCol] = nextDay;
                q.push({newRow, newCol, nextDay});
            }
        }
    }
}

int diffuseNutrient(int R, int C, const vector<vector<int>>& grid) {
    vector<vector<int>> days(R, vector<int>(C, -1));
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j, 0});
                days[i][j] = 0;
            }
        }
    }

    bfs(q, days, grid, R, C);

    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 1) {
                if (days[i][j] != -1) {
                    ans = max(ans, days[i][j]);
                } else {
                    return -1;
                }
            }
        }
    }

    return ans;
}

void testcase() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    cout << diffuseNutrient(R, C, grid) << '\n';
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
//GIEO MẦM