//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 03/10/2024

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void solve() {
    int n; cin >> n;
    cin.ignore();
    vector<vector<int>> adjacencyMatrix(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int number;
        while (ss >> number) {
            adjacencyMatrix[i][number] = adjacencyMatrix[number][i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//CHUYỂN DANH SÁCH KỀ SANG MA TRẬN KỀ