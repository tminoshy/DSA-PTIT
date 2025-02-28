//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 17/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Fear is just an illusion

void DFS(int u, vector<int> &path, vector<bool> &visited, const vector<vector<int>> &graph, vector<vector<int>> &leafPaths) {
    visited[u] = true;
    path.push_back(u);

    bool isLeaf = true;
    for (const int &neighbor : graph[u]) {
        if (!visited[neighbor]) {
            isLeaf = false;
            DFS(neighbor, path, visited, graph, leafPaths);
        }
    }

    if (isLeaf) {
        leafPaths.push_back(path);
    }

    path.pop_back();
    visited[u] = false;
}

bool compare(const vector<int> &a, const vector<int> &b) {
    return a.back() < b.back();
}

void testcase() {
    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(N + 1, false);
    vector<int> path;
    vector<vector<int>> leafPaths;

    DFS(1, path, visited, graph, leafPaths);

    sort(leafPaths.begin(), leafPaths.end(), compare);

    for (const auto &leafPath : leafPaths) {
        for (const int &node : leafPath) {
            cout << node << " ";
        }
        cout << '\n';
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
//ĐƯỜNG ĐI TỚI NODE LÁ