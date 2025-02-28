//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 25/09/2024

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Maze {
    vector<vector<int>> matrix;
    const string directions = "UDLR";
    const vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    string path = "";

    Maze(int N) : matrix(N, vector<int>(N)) {}
};

void findPath(Maze& maze, int row, int col, vector<string>& result) {
    if (row == maze.matrix.size() - 1 && col == maze.matrix.size() - 1) {
        result.push_back(maze.path);
        return;
    }
    for (size_t i = 0; i < 4; i++) {
        int newRow = row + maze.moves[i].first;
        int newCol = col + maze.moves[i].second;
        if (newRow >= 0 && newRow < maze.matrix.size() && newCol >= 0 && newCol < maze.matrix.size() && maze.matrix[newRow][newCol]) {
            maze.matrix[row][col] = 0;
            maze.path.push_back(maze.directions[i]);
            findPath(maze, newRow, newCol, result);
            maze.matrix[row][col] = 1;
            maze.path.pop_back();
        }
    }
}

void testcase() {
    int N; cin >> N;
    Maze maze(N);
    for (vector<int> &row : maze.matrix) {
        for (int &cellValue : row) {
            cin >> cellValue;
        }
    }
    if (!maze.matrix[0][0]) {
        cout << "-1\n";
        return;
    }
    vector<string> result;
    findPath(maze, 0, 0, result);
    if (result.empty()) {
        cout << "-1\n";
        return;
    }
    sort(result.begin(), result.end());
    for (const string& element : result) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    int testCaseCount; cin >> testCaseCount;
    while (testCaseCount--) {
        testcase();
    }
    return 0;
}

//B23DCCE064
//DI CHUYỂN TRONG MÊ CUNG 2