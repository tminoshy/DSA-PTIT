//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/10/2024

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

//Fear is just an illusion

const int INF = numeric_limits<int>::max();

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

bool isValid(int x, int y, int N, const vector<vector<char>>& grid) {
    return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] != 'X';
}

int bfs(int startX, int startY, int endX, int endY, int N, const vector<vector<char>>& grid) {
    int ans = INF;
    vector<vector<vector<int>>> visited(N, vector<vector<int>>(N, vector<int>(4, -1)));
    queue<tuple<int, int, int, int>> q;
    for (int i = 0; i < 4; i++) {
        q.emplace(startX, startY, i, 1);
        visited[startX][startY][i] = 0;
    }
    while (!q.empty()) {
        auto [row, col, dir, turns] = q.front();
        q.pop();
        if (row == endX && col == endY) {
            ans = min(ans, turns);
        }
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            int newTurns = turns + (i != dir);

            if (isValid(newRow, newCol, N, grid) && (visited[newRow][newCol][i] == -1 || visited[newRow][newCol][i] > newTurns)) {
                q.emplace(newRow, newCol, i, newTurns);
                visited[newRow][newCol][i] = newTurns;
            }
        }
    }

    return ans;
}

void testcase() {
    int N;
    cin >> N;
    
    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;

    cout << bfs(startX, startY, endX, endY, N, grid) << '\n';
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
//DI CHUYỂN TRÁNH VẬT CẢN