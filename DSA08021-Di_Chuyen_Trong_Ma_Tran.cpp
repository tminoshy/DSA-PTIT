//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 02/10/2024

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int findMinStep(int M, int N, const vector<vector<int>>& matrix) {
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    queue<tuple<int, int, int>> myqueue;
    myqueue.push({0, 0, 0});
    while (myqueue.empty() == false) {
        auto [row, col, move] = myqueue.front();
        myqueue.pop();
        if (row == M - 1 && col == N - 1) {
            return move;
        }
        int step = matrix[row][col];
        if (row + step < M && visited[row + step][col] == false) {
            visited[row + step][col] = true;
            myqueue.push({row + step, col, move + 1});
        }
        if (col + step < N && visited[row][col + step] == false) {
            visited[row][col + step] = true;
            myqueue.push({row, col + step, move + 1});
        }
    }
    return -1;
}

void testcase() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> matrix(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << findMinStep(M, N, matrix) << endl;
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
//DI CHUYỂN TRONG MA TRẬN