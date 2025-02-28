//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 04/10/2024

#include <iostream>
#include <vector>

using namespace std;

// 2
// 4 5
// 1 2
// 3 5
// 3 6
// 4

void testcase() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> outDegree(V + 1);
    vector<vector<int>> inDegree(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        outDegree[u].push_back(v);
        inDegree[v].push_back(u);
    }
    for (int i = 1; i <= V; i++) {
        if (outDegree[i].size() != inDegree[i].size()) {
            cout << "0\n";
            return;
        }
    }
    cout << "1\n";
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
//CHU TRÌNH EULER TRONG ĐỒ THỊ CÓ HƯỚNG