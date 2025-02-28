#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 1001;
const int LOG = 10; // log2(1000) is approximately 10

vector<int> graph[MAXN];
int depth[MAXN];
int parent[MAXN][LOG];

void dfs(int node, int par) {
    parent[node][0] = par;
    for (int i = 1; i < LOG; i++) {
        if (parent[node][i-1] != -1) {
            parent[node][i] = parent[parent[node][i-1]][i-1];
        } else {
            parent[node][i] = -1;
        }
    }
    for (int neighbor : graph[node]) {
        if (neighbor != par) {
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor, node);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) {
        if ((diff >> i) & 1) {
            u = parent[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int distance(int u, int v) {
    int lca_uv = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[lca_uv];
}

void testcase() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        graph[i].clear();
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    depth[1] = 0;
    dfs(1, -1);

    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        cout << distance(u, v) << '\n';
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