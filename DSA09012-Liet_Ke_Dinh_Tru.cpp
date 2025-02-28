//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int u, vector<bool>& visited, const vector<vector<int>>& adjacencyList) {
    if (!visited[u]) {
        visited[u] = true;
        for (const int& neighbor : adjacencyList[u]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited, adjacencyList);
            }
        }
    }
}

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
    for (int i = 1; i <= V; i++) {
        vector<bool> visited(V + 1, false);
        visited[i] = true;
        int componentCount = 0;
        for (int j = 1; j <= V; j++) {
            if (!visited[j]) {
                componentCount++;
                DFS(j, visited, adjacencyList);
            }
        }
        if (componentCount > 1) {
            cout << i << " ";
        }
    }
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
//LIỆT KÊ ĐỈNH TRỤ