//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 24/10/2024

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//Fear is just an illusion

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool isValid(int row, int col, int N) {
    return (row >= 1 && row <= N && col >= 1 && col <= N);
}

void DFS(pair<int, int> u, int N, const set<pair<pair<int, int>, pair<int, int>>>& edges, vector<vector<bool>>& visited) {
    visited[u.first][u.second] = true;
    for (int i = 0; i < 4; i++) {
        int x = u.first + dx[i];
        int y = u.second + dy[i];
        if (isValid(x, y, N) && !visited[x][y] && edges.count({u, {x, y}}) == 0) {
            DFS({x, y}, N, edges, visited);
        }
    }
}

int main() {
    int N, M, K;
    cin >> N >> K >> M;
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1));
    set<pair<pair<int, int>, pair<int, int>>> edges;
    vector<pair<int, int>> located(K);
    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        edges.insert({ {a, b}, {c, d} });
        edges.insert({ {c, d}, {a, b} });
    }

    for (int i = 0; i < K; i++) {
        cin >> located[i].first;
        cin >> located[i].second;
    }

    int count = 0;
    for (const pair<int, int>& x : located) {
        for (int j = 0; j < N + 1; j++) {
            fill(visited[j].begin(), visited[j].end(), false);
        }
        DFS(x, N, edges, visited);
        for (const pair<int, int>& y : located) {
            if (!visited[y.first][y.second]) {
                count++;
            }
        }
    }

    cout << count / 2 << '\n';

    return 0;
}