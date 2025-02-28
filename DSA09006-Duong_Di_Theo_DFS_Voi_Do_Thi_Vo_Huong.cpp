//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <vector> 

using namespace std;

bool DFS(int s, int t, vector<int>& path, vector<bool>& visited, const vector<vector<int>>& adjacencyList) {
    if (s == t) {
        path.push_back(s);
        return true;
    }
    path.push_back(s);
    visited[s] = true;
    for (int neighbor : adjacencyList[s]) {
        if (!visited[neighbor]) {
            if (DFS(neighbor, t, path, visited, adjacencyList)) {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

void testcase() {
    int V, E, s, t;
    cin >> V >> E >> s >> t;
    vector<vector<int>> adjacencyList(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    vector<int> path;
    vector<bool> visited(V + 1);
    if (DFS(s, t, path, visited, adjacencyList)) {
        for (const int& value : path) {
            cout << value << " ";
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
//ĐƯỜNG ĐI THEO DFS VỚI ĐỒ THỊ VÔ HƯỚNG