//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 31/10/2024

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;

//Fear is just an illusion

vector<vector<int>> rotateSquare(char LorR, const vector<vector<int>>& square) {
    vector<vector<int>> rotated(2, vector<int>(3));

    if (LorR == 'L') {
        rotated[0][0] = square[1][0];
        rotated[0][1] = square[0][0];
        rotated[0][2] = square[0][2];
        rotated[1][0] = square[1][1];
        rotated[1][1] = square[0][1];
        rotated[1][2] = square[1][2];
    } else if (LorR == 'R') {
        rotated[0][0] = square[0][0];
        rotated[0][1] = square[1][1];
        rotated[0][2] = square[0][1];
        rotated[1][0] = square[1][0];
        rotated[1][1] = square[1][2];
        rotated[1][2] = square[0][2];
    }

    return rotated;
}

bool compareRectangles(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != b[i][j]) return false;
        }
    }

    return true;
}

void testcase() {
    vector<vector<int>> S(2, vector<int>(3));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> S[i][j];
        }
    }

    vector<vector<int>> T(2, vector<int>(3));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> T[i][j];
        }
    }

    queue<pair<int, vector<vector<int>>>> q;
    q.push({0, S});

    map<vector<vector<int>>, int> mp;
    mp[S] = 0;

    int ans = INT_MAX;
    while (!q.empty()) {
        auto [steps, current] = q.front();
        q.pop();

        if (compareRectangles(current, T)) {
            ans = min(ans, steps);
        }

        vector<vector<int>> rotateL = rotateSquare('L', current);
        if (mp[rotateL] == 0 || mp[rotateL] > steps + 1) {
            q.push({steps + 1, rotateL});
            mp[rotateL] = steps + 1;
        }

        vector<vector<int>> rotateR = rotateSquare('R', current);
        if (mp[rotateR] == 0 || mp[rotateR] > steps + 1) {
            q.push({steps + 1, rotateR});
            mp[rotateR] = steps + 1;
        }
    }

    cout << ans << '\n';
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
//QUAY HÌNH VUÔNG