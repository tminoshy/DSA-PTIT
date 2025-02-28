//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 03/10/2024

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int u, vector<bool>& visited, const vector<vector<int>>& adjacencyList) {
    queue<int> Vertices;
    Vertices.push(u);
    visited[u] = true;
    while (Vertices.empty() == false) {
        int currentVertices = Vertices.front();
        cout << currentVertices << " ";
        Vertices.pop();
        for (int neighbour : adjacencyList[currentVertices]) {
            if (visited[neighbour] == false) {
                Vertices.push(neighbour);
                visited[neighbour] = true;
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
    vector<bool> visited(V + 1, false);
    BFS(u, visited, adjacencyList);
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
//BFS TRÊN ĐỒ THỊ CÓ HƯỚNG