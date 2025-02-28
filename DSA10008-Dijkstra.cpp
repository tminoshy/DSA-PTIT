//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 25/10/2024

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

//Fear is just an illusion

void dijkstra(int start, const vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

void testcase() {
    int V, E, u;
    cin >> V >> E >> u;

    vector<vector<pair<int, int>>> graph(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<int> dist(V + 1, INT_MAX);
    dijkstra(u, graph, dist);

    for (int i = 1; i <= V; i++) {
        cout << (dist[i] == INT_MAX ? -1 : dist[i]) << " ";
    }
    cout << '\n';
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
//DIJKSTRA