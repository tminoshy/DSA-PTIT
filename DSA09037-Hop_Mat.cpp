//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 21/10/2024

#include <iostream>
#include <vector>

using namespace std;

//Fear is just an illusion

void dfs(int u, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[u] = true;
    
    for (const int& neighbor : graph[u]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
    }
}

void solve() {
    int K, N, M;
    cin >> K >> N >> M;
    
    vector<int> location(K);
    for (int& value : location) {
        cin >> value;
    }

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
    for (int i = 0; i < K; i++) {
        dfs(location[i], visited[location[i]], graph);
    }

    int count = 0;

    for (int i = 1; i <= N; i++) {
        bool valid = true;
        for (int j = 0; j < K; j++) {
            if (!visited[location[j]][i]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            count++;
        }
    }

    cout << count;

}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//HỌP MẶT