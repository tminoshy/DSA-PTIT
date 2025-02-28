//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 09/10/2024

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

void testcase() {
    int S, T;
    cin >> S >> T;

    queue<pair<int, int>> q;
    unordered_set<int> visited;

    visited.insert(S);
    q.push({S, 0});

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        if (current.first == T) {
            cout << current.second << '\n';
            return;
        }

        if (current.first > 1 && visited.find(current.first - 1) == visited.end()) {
            visited.insert(current.first - 1);
            q.push({current.first - 1, current.second + 1});
        }

        if (current.first < 10000 && visited.find(current.first * 2) == visited.end()) {
            visited.insert(current.first * 2);
            q.push({current.first * 2, current.second + 1});
        }
    }
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
//BIẾN ĐỔI S – T