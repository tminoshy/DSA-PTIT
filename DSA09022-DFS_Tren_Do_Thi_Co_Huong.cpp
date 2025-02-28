//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 03/10/2024

#include <iostream>
#include <vector>

using namespace std;

void DFS(int u, vector<bool>& visited, const vector<vector<int>>& adjacencyList) {
    if (visited[u] == false) {
        visited[u] = true;
        cout << u << " ";
        for (int neighbor : adjacencyList[u]) {
            if (visited[neighbor] == false) {
                DFS(neighbor, visited, adjacencyList);
                visited[neighbor] = true;
            }
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
    }
    vector<bool> visited(E + 1);
    DFS(u, visited, adjacencyList);
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
//DFS TRÊN ĐỒ THỊ CÓ HƯỚNG