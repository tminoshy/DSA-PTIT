//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool BFS(int s, int t, vector<bool>& visited, vector<int>& parent, const vector<vector<int>>& adjacencyList) {
    queue<int> myqueue;
    myqueue.push(s);
    visited[s] = true;
    while (!myqueue.empty()) {
        int current = myqueue.front();
        if (current == t) {
            return true;
        }
        myqueue.pop();
        for (int neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                parent[neighbor] = current;
                myqueue.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return false;
}

void testcase() {
    int V, E, s, t;
    cin >> V >> E >> s >> t;
    vector<vector<int>> adjacencyList(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    vector<int> parent(V + 1, -1);
    vector<bool> visited(V + 1, false);
    if (BFS(s, t, visited, parent, adjacencyList)) {
        vector<int> path;
        int x = t;
        for (int i = x; i != -1; i = parent[i]) {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        for (const int& value : path) {
            cout << value << " ";
        }
        cout << endl;
    } else {
        cout << "-1\n";
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
//ĐƯỜNG ĐI THEO BFS TRÊN ĐỒ THỊ VÔ HƯỚNG