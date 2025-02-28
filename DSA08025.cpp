//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>

using namespace std;

vector<pair<int,int>> knightMoves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int knightTour(pair<int, int> startPoint, pair<int, int> endPoint) {
    vector<vector<int>> visited(9, vector<int>(9, 0));
    queue<pair<int, int>> move;
    visited[startPoint.first][startPoint.second] = 1;
    move.push(startPoint);
    while (!move.empty()) {
        pair<int, int> current = move.front();
        move.pop();
        for (int i = 0; i < 8; i++) {
            int currentI = current.first + knightMoves[i].first;
            int currentJ = current.second + knightMoves[i].second;
            if (currentI > 0 && currentI < 9 && currentJ > 0 && currentJ < 9 && !visited[currentI][currentJ]) {
                if (currentI == endPoint.first && currentJ == endPoint.second) {
                    return visited[current.first][current.second];
                }
                visited[currentI][currentJ] = visited[current.first][current.second] + 1;
                move.push({currentI, currentJ});
            }
        }
    }
    return -1;
}

void Testcase() {
    string start, end;
    cin >> start >> end;
    pair<int, int> startPoint = make_pair(start[1] - '0', start[0] - 'a' + 1);
    pair<int, int> endPoint = make_pair(end[1]- '0', end[0] - 'a' + 1);

    if (startPoint == endPoint) {
        cout << 0 << endl;
    } else {
        cout << knightTour(startPoint, endPoint) << endl;
    }
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}