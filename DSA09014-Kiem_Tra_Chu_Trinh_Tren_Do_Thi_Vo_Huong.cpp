//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 10/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(int u, int parent, vector<bool> &visited, const vector<vector<int>> &graph) {
    visited[u] = true;

    for (const int &neighbor : graph[u]) {
        if (!visited[neighbor]) {
            DFS(neighbor, u, visited, graph);
        } else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

void testcase() {
    int E, V;
    cin >> E >> V;
    vector<vector<int>> graph(E + 1);

    for (int i = 0; i < V; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(E + 1);
    for (int i = 1; i <= E; i++) {
        fill(visited.begin(), visited.end(), false);
        if (DFS(i, -1, visited, graph)) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';

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
//KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ VÔ HƯỚNG