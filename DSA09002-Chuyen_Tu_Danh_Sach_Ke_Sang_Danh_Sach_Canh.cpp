//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 03/10/2024

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void solve() {
    int N; cin >> N;
    cin.ignore();
    vector<vector<int>> adjacencyList(N + 1);
    for (int i = 1; i <= N; i++) {
        string line; getline(cin, line);
        stringstream ss(line);
        int neighbor;
        while (ss >> neighbor) {
            adjacencyList[i].push_back(neighbor);
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < adjacencyList[i].size(); j++) {
            if (i < adjacencyList[i][j]) {
                cout << i << " " << adjacencyList[i][j] << endl; 
            }
        }
    }
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//CHUYỂN TỪ DANH SÁCH KỀ SANG DANH SÁCH CẠNH