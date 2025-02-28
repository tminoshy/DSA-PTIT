//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 18/09/2024

#include <iostream>
#include <vector>

using namespace std;

void countPath(size_t row, size_t col, const vector<vector<int>>& matrix, int& count) {
    if (row == matrix.size() - 1 && col == matrix[0].size() - 1) {
        count++;
        return;
    }
    if (row < matrix.size() - 1) {
        countPath(row + 1, col, matrix, count);
    }
    if (col < matrix[0].size() - 1) {
        countPath(row, col + 1, matrix, count);
    }
}

void testcase() {
    size_t M, N;
    cin >> M >> N;
    vector<vector<int>> matrix(M, vector<int>(N));
    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    int count = 0;
    countPath(0, 0, matrix, count);
    cout << count << endl;
}

int main() {
    int testCaseCount; cin >> testCaseCount;
    while(testCaseCount--) {
        testcase();
    }
    return 0;
}

//B23DCCE064
//DI CHUYỂN TRONG MA TRẬN