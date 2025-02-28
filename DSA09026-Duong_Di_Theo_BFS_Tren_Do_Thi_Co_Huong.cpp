//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 03/10/2024

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int current, int t, vector<bool>& visited, const vector<vector<int>>& adjacencyList, vector<int>& parent) {
    queue<int> Vertices;
    Vertices.push(current);
    visited[current] = true;
    while (Vertices.empty() == false) {
        int currentVertices = Vertices.front();
        Vertices.pop();
        if (currentVertices == t) {
            return;
        }
        
        for (int neighbor : adjacencyList[currentVertices]) {
            if (visited[neighbor] == false) {
                Vertices.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = currentVertices;
            }
        }
    }
}

void testcase() {
    int V, E, s, t;
    cin >> V >> E >> s >> t;
    vector<vector<int>> adjacencyList(V + 1);
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
    }
    vector<bool> visited(V + 1, false);
    vector<int> parent(V + 1, -1);
    BFS(s, t, visited, adjacencyList, parent);
    if (visited[t] == false) {
        cout << "-1\n";
        return;
    }
    vector<int> path;
    for (int i = t; i != -1; i = parent[i]) {
        path.push_back(i);
    }
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
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
//ĐƯỜNG ĐI THEO BFS TRÊN ĐỒ THỊ CÓ HƯỚNG