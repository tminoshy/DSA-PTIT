//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int u, vector<bool>& visited, const vector<vector<int>>& adjacencyList) {
    queue<int> myqueue;
    myqueue.push(u);
    visited[u] = true;
    while (!myqueue.empty()) {
        int current = myqueue.front();
        myqueue.pop();
        for (const int& neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                myqueue.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void testcase() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adjacencyList(V + 10);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    vector<bool> visited(V + 1, false);
    int component_count = 0;
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            component_count++;
            BFS(i, visited, adjacencyList);
        }
    }
    cout << component_count << endl;
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
//TÌM SỐ THÀNH PHẦN LIÊN THÔNG VỚI BFS