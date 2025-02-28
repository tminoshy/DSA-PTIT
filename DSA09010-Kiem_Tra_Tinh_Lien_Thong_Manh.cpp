//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 09/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int u, vector<bool> &visited, const vector<vector<int>> &adjacencyList) {
    if (!visited[u]) {
        visited[u] = true;

        for (const int &neighbor : adjacencyList[u]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited, adjacencyList);
            }
        }
    }
}

void testcase() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adjacencyList(V + 1);
    vector<vector<int>> reverseList(V + 1);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        reverseList[v].push_back(u);
    }

    vector<bool> visited(V + 1, false);

    DFS(1, visited, adjacencyList);
    for (int i = 1; i < visited.size(); i++) {
        if (visited[i] == false) {
            cout << "NO" << '\n';
            return;
        }
    }

    fill(visited.begin(), visited.end(), false);
    DFS(1, visited, reverseList);
    for (int i = 1; i < visited.size(); i++) {
        if (visited[i] == false) {
            cout << "NO" << '\n';
            return;
        }
    }
    
    cout << "YES" << '\n';
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
//KIỂM TRA TÍNH LIÊN THÔNG MẠNH