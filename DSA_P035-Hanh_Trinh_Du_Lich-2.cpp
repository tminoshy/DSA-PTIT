//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 3/11/2024

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Fear is just an illusion

const long long INF = 1e18;

vector<long long> Dijkstra(int start, int N, const vector<vector<pair<int, long long>>>& graph) {
    vector<long long> dist(N + 1, INF);
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [distance, Node] = pq.top();
        pq.pop();

        if (distance > dist[Node]) continue;

        for (const pair<int, long long>& neighbor : graph[Node]) {
            if (distance + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = distance + neighbor.second;
                pq.push({dist[neighbor.first], neighbor.first});
            }
        }
    }

    return dist;
}

void solve() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> s(K);
    for (int i = 0; i < K; i++) {
        cin >> s[i];
    }

    s.insert(s.begin(), 1);
    K++;

    vector<vector<pair<int, long long>>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
    }

    vector<vector<long long>> dist(N + 1, vector<long long>(N + 1, INF));
    for (int i = 0; i <= K; i++) {
        dist[i] = Dijkstra(s[i], N, graph);
    }

    vector<vector<long long>> simpleDist(K, vector<long long>(K));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            simpleDist[i][j] = dist[i][s[j]];
        }
    }


    vector<vector<long long>> dp((1<<K), vector<long long>(K, INF));
    for (int i = 0; i < K; i++) {
        dp[1<<i][i] = simpleDist[0][i];
    }

    for (int mask = 1; mask < (1<<K); mask++) {
        for (int u = 0; u < K; u++) {
            if (!((1<<u) & mask)) continue;

            for (int v = 0; v < K; v++) {
                if ((1<<v) & mask) continue;

                int newMask = (1<<v) | mask;
                dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + simpleDist[u][v]);
            }
        }
    }

    long long ans = INF;
    for (int i = 1; i < K; i++) {
        if (simpleDist[i][0] < INF) {
            ans = min(ans, dp[(1 << K) - 1][i] + simpleDist[i][0]);
        }
    }

    cout << ((ans == INF) ? -1 : ans) << '\n';
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//HÀNH TRÌNH DU LỊCH - 2