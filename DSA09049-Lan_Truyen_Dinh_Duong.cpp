//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 28/10/2024

#include <iostream>
#include <vector>

using namespace std;

//Fear is just an illusion

long long DFS(long long u, const vector<vector<long long>>& graph, vector<long long>& value) {
    value[u] = 1;
    long long numberOfChild = 0;
    for (const long long& neighbor : graph[u]) {
        numberOfChild += DFS(neighbor, graph, value);
        value[u] += value[neighbor];
    }
    value[u] += numberOfChild;

    return numberOfChild + 1;
}

void solve() {
    long long N;
    cin >> N;
    vector<vector<long long>> graph(N + 1);
    for (long long i = 2; i <= N; i++) {
        long long val;
        cin >> val;
        graph[val].push_back(i);
    }

    vector<long long> value(N + 1);
    DFS(1, graph, value);
    
    for (long long i = 1; i <= N; i++) {
        cout << value[i] << " ";
    }
    cout << '\n';
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//LAN TRUYỀN DINH DƯỠNG