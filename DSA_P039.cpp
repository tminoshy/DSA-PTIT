#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSum;
vector<vector<int>> matrix;
vector<bool> usedColumns;

void backtrack(int row, int currentSum, int N) {
    if (row == N) {
        maxSum = max(maxSum, currentSum);
        return;
    }
    for (int col = 0; col < N; ++col) {
        if (!usedColumns[col]) {
            usedColumns[col] = true;
            backtrack(row + 1, currentSum + matrix[row][col], N);
            usedColumns[col] = false;
        }
    }
}

void solve() {
    int N;
    cin >> N;
    matrix.assign(N, vector<int>(N));
    usedColumns.assign(N, false);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }
    maxSum = 0;
    backtrack(0, 0, N);
    cout << maxSum << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}