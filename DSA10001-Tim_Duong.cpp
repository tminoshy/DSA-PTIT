//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 19/10/2024

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

//Fear is just an illusion

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

bool isValid(int x, int y, int N, int M, const vector<vector<char>>& grid) {
    return x >= 0 && x < N && y >= 0 && y < M && grid[x][y] != '*';
}

bool bfs(int startX, int startY, int endX, int endY, int N, int M, const vector<vector<char>>& grid) {
    vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(4, -1)));
    queue<tuple<int, int, int, int>> q;
    for (int i = 0; i < 4; i++) {
        q.emplace(startX, startY, i, 0);
        visited[startX][startY][i] = 0;
    }
    while (!q.empty()) {
        auto [row, col, dir, turns] = q.front();
        q.pop();
        if (row == endX && col == endY) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            int newTurns = turns + (i != dir);

            if (isValid(newRow, newCol, N, M, grid) && (visited[newRow][newCol][i] == -1 || visited[newRow][newCol][i] > newTurns) && newTurns <= 2) {
                q.emplace(newRow, newCol, i, newTurns);
                visited[newRow][newCol][i] = newTurns;
            }
        }
    }

    return false;
}

void testcase() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<char>> grid(N, vector<char>(M));
    int startX, startY;
    int endX, endY;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                startX = i;
                startY = j;
            } else if (grid[i][j] == 'T') {
                endX = i;
                endY = j;
            }
        }
    }
    if (bfs(startX, startY, endX, endY, N, M, grid)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
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
//TÌM ĐƯỜNG