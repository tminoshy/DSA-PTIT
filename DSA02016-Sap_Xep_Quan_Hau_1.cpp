//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 19/09/2024

#include <iostream>
#include <vector>

using namespace std;

struct Queen {
    vector<int> columnOccupied, positiveDiagonal, negativeDiagonal;

    Queen(int n) : columnOccupied(n + 1, 0), positiveDiagonal(n * 2, 0), negativeDiagonal(n * 2, 0) {}
};

void calculateNqueens(int boardSize, int &solutionCount, int currentRow, Queen &queen) {
    for (size_t col = 1; col <= boardSize; col++) {
        if (!queen.columnOccupied[col] && !queen.positiveDiagonal[currentRow + col - 1] && !queen.negativeDiagonal[currentRow - col + boardSize]) {
            queen.columnOccupied[col] = queen.positiveDiagonal[currentRow + col - 1] = queen.negativeDiagonal[currentRow - col + boardSize] = 1;
            if (currentRow == boardSize) {
                solutionCount++;
            } else {
                calculateNqueens(boardSize, solutionCount, currentRow + 1, queen);
            }
            queen.columnOccupied[col] = queen.positiveDiagonal[currentRow + col - 1] = queen.negativeDiagonal[currentRow - col + boardSize] = 0;
        }
    }
}

void testcase() {
    int n; cin >> n;
    Queen queen(n);
    int solutionCount = 0;
    calculateNqueens(n, solutionCount, 1, queen);
    cout << solutionCount << endl;
}

int main() {
    int testCaseCount; cin >> testCaseCount;
    while(testCaseCount--) {
        testcase();
    }
    return 0;
}

//B23DCCE064
//SẮP XẾP QUÂN HẬU 1