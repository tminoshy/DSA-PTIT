//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 03/10/2024

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adjacencyMatrix(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//CHUYỂN MA TRẬN KỀ SANG DANH SÁCH KỀ