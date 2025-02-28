//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 11/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(int u, int parent, vector<int> &path, vector<bool> &visited, const vector<vector<int>> &graph) {
    visited[u] = true;
    path.push_back(u);

    for (const int &neighbor : graph[u]) {
        if (!visited[neighbor]) {
            if (DFS(neighbor, u, path, visited, graph)) {
                return true;
            }
        } else if (neighbor == 1 && parent != 1) { // Fix: Check for cycle starting and ending at node 1
            path.push_back(neighbor);
            return true;
        }
    }

    path.pop_back();
    return false;
}

void testcase() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1);
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (vector<int> &vec : graph) {
        sort(vec.begin(), vec.end());
    }

    vector<bool> visited(V + 1, false);
    vector<int> path;
    
    if (DFS(1, -1, path, visited, graph)) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
    } else {
        cout << "NO";
    }
    cout << '\n';
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
//CHU TRÌNH THEO DFS