//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 03/10/2024

#include <iostream>
#include <vector>

using namespace std;

void DFS(int current, int component_id, vector<int>& component, vector<bool>& visited, const vector<vector<int>>& adjacencyList) {
    component[current] = component_id;
    visited[current] = true;
    for (int neighbor : adjacencyList[current]) {
        if (!visited[neighbor]) {
            DFS(neighbor, component_id, component, visited, adjacencyList);
        }
    }
}

void testcase() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adjacencyList(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    vector<bool> visited(N + 1, false);
    int component_id = 0;
    vector<int> component(N + 1, -1);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            component_id++;
            DFS(i, component_id, component, visited, adjacencyList);
        }
    }
    int Q; cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        if (component[x] == component[y]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
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
//KIỂM TRA ĐƯỜNG ĐI