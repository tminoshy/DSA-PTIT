//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 11/10/2024

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int u, vector<bool> &visited, const vector<vector<int>> &graph) {
    int count = 0;
    queue<int> myqueue;
    myqueue.push(u);
    visited[u] = true;
    
    while (!myqueue.empty()) {
        int current = myqueue.front();
        myqueue.pop();
        count++;

        for (const int &neighbor : graph[current]) {
            if (!visited[neighbor]) {
                myqueue.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return count;
}

void testcase() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(N + 1, false);

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            ans = max(ans, BFS(i, visited, graph));
        }
    }
    
    cout << ans << '\n';
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
//KẾT BẠN