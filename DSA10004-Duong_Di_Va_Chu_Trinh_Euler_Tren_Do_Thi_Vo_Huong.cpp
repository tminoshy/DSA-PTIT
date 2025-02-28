//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 04/10/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adjacencyList(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    int oddEdgesCount = 0;
    for (int i = 1; i <= V; i++) {
        oddEdgesCount += (adjacencyList[i].size() % 2 == 1);
    }
    if (oddEdgesCount == 0) cout << "2\n";
    else if (oddEdgesCount == 2) cout << "1\n";
    else cout << "0\n";
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
//ĐƯỜNG ĐI VÀ CHU TRÌNH EULER VỚI ĐỒ THỊ VÔ HƯỚNG