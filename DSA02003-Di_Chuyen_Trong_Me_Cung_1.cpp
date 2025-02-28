//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 18/09/2024

#include <iostream>
#include <vector>

using namespace std;

void findWay(const vector<vector<int>>& matrix, int row, int col, vector<char>& path, int matrixSize, bool& found) {
    if (row == matrixSize - 1 && col == matrixSize - 1) {
        for (char c : path) {
            cout << c;
        }
        cout << " ";
        found = true;
        return;
    }
    if (row < matrixSize - 1 && matrix[row + 1][col] == 1) {
        path.push_back('D');
        findWay(matrix, row + 1, col, path, matrixSize, found);
        path.pop_back();
    }
    if (col < matrixSize - 1 && matrix[row][col + 1] == 1) {
        path.push_back('R');
        findWay(matrix, row, col + 1, path, matrixSize, found);
        path.pop_back();
    }
}

void testcase() {
    int N; cin >> N;
    vector<vector<int>> matrix(N, (vector<int>(N)));
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }
    vector<char> path;
    bool found = false;
    if (matrix[0][0] == 0 || matrix[N - 1][N - 1] == 0) {
        cout << "-1" << endl;
        return;
    }
    findWay(matrix, 0, 0, path, N, found);
    if (!found) {
        cout << "-1";
    }
    cout << endl;
}

int main() {
    int testCaseCount; cin >> testCaseCount;
    while(testCaseCount--) {
        testcase();
    }
    return 0;
}

//B23DCCE064
//DI CHUYỂN TRONG MÊ CUNG 1