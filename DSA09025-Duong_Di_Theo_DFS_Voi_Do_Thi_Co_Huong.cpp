//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 03/10/2024

#include <iostream>
#include <vector>

using namespace std;

void DFS(int current, int t, vector<bool>& visited, const vector<vector<int>>& adjacencyList, vector<int>& path, bool& done) {
    visited[current] = true;
    path.push_back(current);
    
    if (current == t) {
        done = true;
        return;
    }

    for (int neighbor : adjacencyList[current]) {
        if (visited[neighbor] == false) {
            visited[neighbor] = true;
            DFS(neighbor, t, visited, adjacencyList, path, done);
        }
        if (done) return;
    }
    path.pop_back();
}

void testcase() {
    int V, E, s, t;
    cin >> V >> E >> s >> t;
    vector<vector<int>> adjacencyList(V + 1);
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
    }
    vector<bool> visited(V + 1);
    vector<int> path;
    bool done = false;
    DFS(s, t, visited, adjacencyList, path, done);
    if (done == false) {
        cout << "-1\n";
        return;
    }
    for (const int& value : path) {
        cout << value << " ";
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
//ĐƯỜNG ĐI THEO DFS VỚI ĐỒ THỊ CÓ HƯỚNG