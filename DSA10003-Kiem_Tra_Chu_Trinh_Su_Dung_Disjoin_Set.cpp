//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 20/10/2024

#include <iostream>
#include <vector>

using namespace std;

//Fear is just an illusion

class DisjoinSet {
    public: 
        DisjoinSet(int n) : parent(n + 1), rank(n + 1, 0) {
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
        }

        int find(int u) {
            if (u != parent[u]) {
                return find(parent[u]);
            }
            return parent[u];
        }

        bool unionSets(int u, int v) {
            int rootU = find(u);
            int rootV = find(v);

            if (rootU == rootV) {
                return false;
            }

            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootV] < rank[rootU]) {
                parent[rootV] = rootU;
            } else {
                parent[rootU] = rootV;
                rank[rootU]++;
            }

            return true;
        }

    private:
        vector<int> parent;
        vector<int> rank;
};

void testcase() {
    int V, E;
    cin >> V >> E;
    DisjoinSet a(V);
    bool hasCycle = false;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        if (!a.unionSets(u, v)) {
            hasCycle = true;
        }
    }

    if (hasCycle) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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
//KIỂM TRA CHU TRÌNH SỬ DỤNG DISJOIN SET