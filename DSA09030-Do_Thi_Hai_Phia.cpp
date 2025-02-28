//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 19/10/2024

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Fear is just an illusion

bool isPartite(int V, const vector<vector<int>> &graph) {
    vector<int> colors(V + 1, -1);

    for (int i = 1; i <= V; i++) {
        if (colors[i] == -1) {
            queue<int> q;
            colors[i] = 0;
            q.push(i);
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                for (const int &neighbor : graph[current]) {
                    if (colors[neighbor] == -1) {
                        colors[neighbor] = 1 - colors[current];
                        q.push(neighbor);
                    } else {
                        if (colors[neighbor] == colors[current]) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}

void testcase() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if (isPartite(V, graph)) {
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
//ĐỒ THỊ HAI PHÍA