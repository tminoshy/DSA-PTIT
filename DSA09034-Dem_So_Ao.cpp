//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 21/10/2024

#include <iostream>
#include <vector>

using namespace std;

//Fear is just an illusion

int dx[] = {-1, -1, 0, 1, 1,  1,  0, -1};
int dy[] = {0 ,  1, 1, 1, 0, -1, -1, -1};

void DFS(int row, int col, int N, int M, vector<vector<bool>>& visited, const vector<vector<char>> &A) {
        visited[row][col] = true;
        for (int i = 0; i < 8; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && !visited[newRow][newCol] && A[newRow][newCol] == 'W') {
                DFS(newRow, newCol, N, M, visited, A);
            }
        }
}


void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> A(N, vector<char>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    int poolCount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && A[i][j] == 'W') {
                poolCount++;
                DFS(i, j, N, M, visited, A);
            }
        }
    }

    cout << poolCount;
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//ĐẾM SỐ AO