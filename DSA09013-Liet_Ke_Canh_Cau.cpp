//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 03/10/2024

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void DFSwithoutCutEgde(int u, int start, int end, const vector<vector<int>>& adjacencyList, vector<bool>& visited) {
    if (visited[u] == false) {
        visited[u] = true;
        for (int neighbor : adjacencyList[u]) {
            if (u == start && neighbor == end || neighbor == start && u == end) {
                continue;
            }
            DFSwithoutCutEgde(neighbor, start, end, adjacencyList, visited);
        }
    }
}

void testcase() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adjacencyList(V + 1);
    vector<pair<int, int>> edges;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    vector<bool> visited(V + 1);
    for (int i = 0; i < E; i++) {
        fill(visited.begin(), visited.end(), false);
        DFSwithoutCutEgde(edges[0].first, edges[i].first, edges[i].second, adjacencyList, visited);
        for (int j = 1; j <= V; j++) {
            if (visited[j] == false) {
                cout << edges[i].first << " " << edges[i].second << " ";
                break;
            }
            
        }
    }
    cout << endl;
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
//LIỆT KÊ CẠNH CẦU