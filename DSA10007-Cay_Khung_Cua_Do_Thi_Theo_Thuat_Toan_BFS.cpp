//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 20/10/2024

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Fear is just an illusion

void bfs(int u, vector<bool>& visited, const vector<vector<int>>& graph, vector<pair<int, int>>& result) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int currentVal = q.front();
        q.pop();

        for (const int& neighbor : graph[currentVal]) {
            if (!visited[neighbor]) {
                result.push_back({currentVal, neighbor});
                q.push(neighbor);
                visited[neighbor] = true;
            }
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

    vector<bool> visited(N + 1, false);
    vector<pair<int, int>> result;

    bfs(u, visited, graph, result);

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
//CÂY KHUNG CỦA ĐỒ THỊ THEO THUẬT TOÁN BFS