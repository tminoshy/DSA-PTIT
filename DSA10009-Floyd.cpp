//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 25/10/2024

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//Fear is just an illusion

void Floyd(int N, vector<vector<int>>& distance) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (distance[i][k] < INT_MAX && distance[k][j] < INT_MAX) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> distance(N + 1, vector<int>(N + 1, INT_MAX));
    for (int i = 1; i <= N; i++) {
        distance[i][i] = 0;
    }
    
    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        distance[u][v] = c;
        distance[v][u] = c;
    }

    Floyd(N, distance);

    int Q;
    cin >> Q;
    
    while (Q--) {
        int x, y;
        cin >> x >> y;
        if (distance[x][y] == INT_MAX) {
            cout << "-1" << '\n';
        } else {
            cout << distance[x][y] << '\n';
        }
    }
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//FLOYD