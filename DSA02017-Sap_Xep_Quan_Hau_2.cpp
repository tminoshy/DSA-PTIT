//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>

using namespace std;

struct Queen {
    vector<int> columnOccupied, positiveDiagonal, negativeDiagonal;
    vector<vector<int>> cellScore;
    int highestScore = 0, currentSum = 0;

    Queen() : columnOccupied(9, 0), positiveDiagonal(16, 0), negativeDiagonal(16, 0), cellScore(8, vector<int>(8, 0)) {}
};

void nQueenHighestScore(int currentRow, Queen &queen) {
    if (currentRow > 8) {
        if (queen.currentSum > queen.highestScore) {
            queen.highestScore = queen.currentSum;
        }
        return;
    }

    for (size_t col = 1; col <= 8; col++) {
        if (!queen.columnOccupied[col] && !queen.positiveDiagonal[currentRow + col - 1] && !queen.negativeDiagonal[currentRow - col + 8]) {
            queen.columnOccupied[col] = queen.positiveDiagonal[currentRow + col - 1] = queen.negativeDiagonal[currentRow - col + 8] = 1;
            queen.currentSum += queen.cellScore[currentRow - 1][col - 1];
            nQueenHighestScore(currentRow + 1, queen);
            queen.columnOccupied[col] = queen.positiveDiagonal[currentRow + col - 1] = queen.negativeDiagonal[currentRow - col + 8] = 0;
            queen.currentSum -= queen.cellScore[currentRow - 1][col - 1]; 
        }
    }
}

void testcase() {
    Queen queen;
    for (vector<int> &row : queen.cellScore) {
        for (int &cellValue : row) {
            cin >> cellValue;
        }
    }
    nQueenHighestScore(1, queen);
    cout << queen.highestScore << endl;
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
//SẮP XẾP QUÂN HẬU 2