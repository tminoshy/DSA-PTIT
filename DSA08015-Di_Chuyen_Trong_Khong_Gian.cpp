//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 31/10/2024

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

//Fear is just an illusion

int dx[6] = {0, 0, 1,-1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1,-1};
int dz[6] = {1,-1, 0, 0, 0, 0};

struct Point {
    int x, y, z, steps;
};

bool isValid(int x, int y, int z, int A, int B, int C) {
    return x >= 0 && x < A && y >= 0 && y < B && z >= 0 && z < C;
}

int bfs(int startX, int startY, int startZ, int endX, int endY, int endZ, int A, int B, int C, const vector<vector<vector<char>>>& space) {
    queue<Point> q;
    q.push({startX, startY, startZ, 0});
    vector<vector<vector<int>>> stepCount(A, vector<vector<int>>(B, vector<int>(C, -1)));
    stepCount[startX][startY][startZ] = 0;
    
    int ans = INT_MAX;
    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.x == endX && current.y == endY && current.z == endZ) {
            ans = min(ans, current.steps);
        }

        for (int i = 0; i < 6; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            int newZ = current.z + dz[i];
            int newSteps = current.steps + 1;

            if (isValid(newX, newY, newZ, A, B, C) && (space[newX][newY][newZ] == '.' || space[newX][newY][newZ] == 'E') && (stepCount[newX][newY][newZ] == -1 || stepCount[newX][newY][newZ] > newSteps)) {
                q.push({newX, newY, newZ, newSteps});
                stepCount[newX][newY][newZ] = newSteps;
            }
        }
    }

    return (ans == INT_MAX) ? -1 : ans;
}

void testcase() {
    int A, B, C;
    cin >> A >> B >> C;
    
    int startX, startY, startZ, endX, endY, endZ;
    vector<vector<vector<char>>> space(A, vector<vector<char>>(B, vector<char>(C)));
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            for (int k = 0; k < C; k++) {
                cin >> space[i][j][k];
                if (space[i][j][k] == 'S') {
                    startX = i;
                    startY = j;
                    startZ = k;
                } else if (space[i][j][k] == 'E') {
                    endX = i;
                    endY = j;
                    endZ = k;
                }
            }
        }
    }

    cout << bfs(startX, startY, startZ, endX, endY, endZ, A, B, C, space) << '\n';
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
//DI CHUYỂN TRONG KHÔNG GIAN