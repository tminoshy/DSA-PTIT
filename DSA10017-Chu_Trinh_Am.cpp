//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/10/2024

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

//Fear is just an illusion

const int INF = numeric_limits<int>::max();

bool detectNegativeCycle(int u, int N, const vector<vector<pair<int, int>>>& graph, vector<long long>& distance) {
    distance[u] = 0;
    int count = 0;
    bool modified;
    do {
        modified = false;
        for (int i = 1; i <= N; i++) {
            for (const pair<int, int>& edge : graph[i]) {
                if (distance[i] != INF && distance[i] + edge.second < distance[edge.first]) {
                    distance[edge.first] = distance[i] + edge.second;
                    modified = true;
                }
            }
        }
        
        if (modified) {
            count++;
        } else {
            break;
        }

        if (count >= N - 1) return true;

    } while (modified);

    return false;
}

void testcase() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<long long> distance(V + 1, INF);
    
    for (int i = 1; i <= V; i++) {
        if (detectNegativeCycle(i, V, graph, distance)) {
            cout << "1" << '\n';
            return;
        }
    }
    cout << "0" << '\n';
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
//CHU TRÌNH ÂM