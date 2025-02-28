//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 03/10/2024

#include <iostream>
#include <vector>

using namespace std;

void DFS(int u, const vector<vector<int>>& adjacencyList, vector<bool>& visited) {
    if (visited[u] == false) {
        visited[u] = true;
        cout << u << " ";
        for (int i = 0; i < adjacencyList[u].size(); i++) {
            DFS(adjacencyList[u][i], adjacencyList, visited);
        }
    }
}

void testcase() {
    int V, E, u;
    cin >> V >> E >> u;
    vector<vector<int>> adjacencyList(V + 1);
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    vector<bool> visited(V + 1, false);
    DFS(u, adjacencyList, visited);
    cout << endl;
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
//DFS TRÊN ĐỒ THỊ VÔ HƯỚNG