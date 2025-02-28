//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <vector>

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
    vector<vector<int>> adjacencyList(V + 10);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    vector<bool> visited(V + 1, false);
    int component_count = 0;
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            component_count++;
            DFS(i, visited, adjacencyList);
        }
    }
    cout << component_count << endl;
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
//ĐẾM SỐ THÀNH PHẦN LIÊN THÔNG