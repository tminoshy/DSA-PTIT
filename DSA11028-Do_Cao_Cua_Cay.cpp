//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 15/10/2024

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findDepthByBFS(const vector<vector<int>> &graph, vector<bool> &visited) {
    queue<pair<int, int>> q;
    int u = 1;
    q.push({u, 0});
    visited[u] = true;
    int maxLevel = 0;
    
    while (!q.empty()) {
        auto [currentNode, level] = q.front();
        q.pop();
        maxLevel = max(maxLevel, level);
        for (const int &neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                q.push({neighbor, level + 1});
                visited[neighbor] = true;
            }
        }
    }

    return maxLevel;
}

void testcase() {
    int N;
    cin >> N;
    
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(N + 1, false);

    cout << findDepthByBFS(graph, visited) << '\n';
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
//ĐỘ CAO CỦA CÂY