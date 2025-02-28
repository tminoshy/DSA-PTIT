//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 11/10/2024

#include <iostream>
#include <vector>

using namespace std;

bool isValidColor(int vertex, int color ,const vector<int> &colors, const vector<vector<int>> &graph) {
    for (const int &neighbor : graph[vertex]) {
        if (colors[neighbor] == color) {
            return false;
        }
    }
    
    return true;
}

bool colorGraph(int vertex, int M, int V, vector<int> &colors, const vector<vector<int>> &graph) {
    if (vertex == V + 1) {
        return true;
    }

    for (int i = 1; i <= M; i++) {
        if (isValidColor(vertex, i, colors, graph)) {
            colors[vertex] = i;
            if (colorGraph(vertex + 1, M, V, colors, graph)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }

    return false;
}

void testcase() {
    int V, E, M;
    cin >> V >> E >> M;
    vector<vector<int>> graph(V + 1);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> colors(V + 1, 0);

    if (colorGraph(1, M, V, colors, graph)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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
//TÔ MÀU ĐỒ THỊ