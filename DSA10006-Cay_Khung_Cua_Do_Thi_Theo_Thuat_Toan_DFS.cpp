//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 20/10/2024

#include <iostream>
#include <vector>

using namespace std;

//Fear is just an illusion

void dfs(int u, vector<bool>& visited, const vector<vector<int>>& graph, vector<pair<int, int>>& result) {
    visited[u] = true;
    for (const int& neighbor : graph[u]) {
        if (!visited[neighbor]) {
            result.push_back({u, neighbor});
            dfs(neighbor, visited, graph, result);
        }
    }
}

void testcase() {
    int N, M, u;
    cin >> N >> M >> u;

    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<pair<int, int>> result;
    vector<bool> visited(N + 1, false);

    dfs(u, visited, graph, result);

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << "-1" << '\n';
            return;
        }
    }

    for (const pair<int, int>& edge : result) {
        cout << edge.first << " " << edge.second << '\n';
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
//CÂY KHUNG CỦA ĐỒ THỊ THEO THUẬT TOÁN DFS