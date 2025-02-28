//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 10/10/2024

#include <iostream>
#include <vector>

using namespace std;

const vector<pair<int, int>> direction = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void DFS(int row, int col, int N, int M, vector<vector<bool>>& visited, const vector<vector<int>> &A) {
        visited[row][col] = true;
        for (int i = 0; i < 8; i++) {
            int newRow = row + direction[i].first;
            int newCol = col + direction[i].second;
            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && !visited[newRow][newCol] && A[newRow][newCol] == 1) {
                DFS(newRow, newCol, N, M, visited, A);
            }
        }
}

void testcase() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    int componentCount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && A[i][j] == 1) {
                componentCount++;
                DFS(i, j, N, M, visited, A);
            }
        }
    }

    cout << componentCount << '\n';
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
//SỐ LƯỢNG HÒN ĐẢO