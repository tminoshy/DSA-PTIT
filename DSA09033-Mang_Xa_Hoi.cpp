//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 11/10/2024

#include <iostream>
#include <vector>

using namespace std;

void DFS(int u, int &Vcount, int &Ecount, vector<bool> &visited, const vector<vector<int>> &graph) {
    Vcount++;
    visited[u] = true;

    for (const int &neighbor : graph[u]) {
        Ecount++;
        if (!visited[neighbor]) {
            DFS(neighbor, Vcount, Ecount, visited, graph);
        }
    }
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
    
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            int Vcount = 0, Ecount = 0;
            DFS(i, Vcount, Ecount, visited, graph);
            if (Ecount != Vcount * (Vcount - 1)) {
                cout << "NO" << '\n';
                return;
            }
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
//MẠNG XÃ HỘI