//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 26/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Fear is just an illusion

struct Edge {
    int src, dest, weight;
};

bool compare(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class DisjoinSet {
    public:
        vector<int> rank;
        vector<int> parent;

        DisjoinSet(int V) : rank(V + 1), parent(V + 1) {
            for (int i = 1; i <= V; i++) {
                parent[i] = i;
            }
        }

        int findRoot(int a) {
            if (a != parent[a]) {
                return findRoot(parent[a]);
            }
            return parent[a];
        }

        bool unionSet(int a, int b) {
            int rootA = findRoot(a);
            int rootB = findRoot(b);

            if (rootA == rootB) return false;

            if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }

            return true;
        }

        int Kruskal(const vector<Edge>& edges, int V) {
            int edgeCount = 0;
            int totalWeight = 0;
            
            for (const auto& edge : edges) {
                if (findRoot(edge.src) != findRoot(edge.dest)) {
                    unionSet(edge.src, edge.dest);
                    totalWeight += edge.weight;
                    edgeCount++;
                }

                if (edgeCount == V - 1) break;
            }

            return totalWeight;
        }
};

void testcase() {
    int V, E;
    cin >> V >> E;
    
    DisjoinSet a(V);

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++) {
        cin >> edges[i].src;
        cin >> edges[i].dest;
        cin >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), compare);

    cout << a.Kruskal(edges, V) << '\n';

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
//KRUSKAL