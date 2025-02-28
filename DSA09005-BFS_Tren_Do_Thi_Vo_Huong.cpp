//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 03/10/2024

#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

void BFS(int u, const vector<vector<int>>& adjacencyList, vector<bool>& visited) {
    queue<int> vertices;
    vertices.push(u);
    visited[u] = true;
    while (vertices.empty() == false) {
        int currentVertice = vertices.front();
        vertices.pop();
        cout << currentVertice << " ";
        for (int neighbor : adjacencyList[currentVertice]) {
            if (visited[neighbor] == false) {
                vertices.push(neighbor);
                visited[neighbor] = true;
            }
        }
        
    }
}

void testcase() {
    int V, E, u;
    cin >> V >> E >> u;
    cin.ignore();
    vector<vector<int>> adjacencyList(V + 1);
    string line;
    getline(cin, line);
    stringstream ss(line);
    int a, b;
    while (ss >> a >> b) {
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    vector<bool> visited(V + 1, false);
    BFS(u, adjacencyList, visited);
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
//BFS TRÊN ĐỒ THỊ VÔ HƯỚNG