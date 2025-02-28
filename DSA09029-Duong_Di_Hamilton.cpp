//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 17/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Fear is just an illusion

bool isHamiltonianPath(int u, int V, vector<bool> &visited, const vector<vector<int>> &graph, int count) {
    if (count == V) {
        return true;
    }

    for (const int &neighbor : graph[u]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            if (isHamiltonianPath(neighbor, V, visited, graph, count + 1)) {
                return true;
            }
            visited[neighbor] = false;
        }
    }

    return false;
}

void testcase() {
    int V, E;
    cin >> V >> E;
    
    vector<vector<int>> graph(V + 10);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(V + 1, false);
    for (int i = 1; i <= V; i++) {
        fill(visited.begin(), visited.end(), false);
        visited[i] = true;
        if (isHamiltonianPath(i, V, visited, graph, 1)) {
            cout << "1" << '\n';
            return;
        }
    }

    cout << "0" << '\n';
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
//ĐƯỜNG ĐI HAMILTON