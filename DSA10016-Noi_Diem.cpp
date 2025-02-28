//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 28/10/2024

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

//Fear is just an illusion

struct edge {
    double weight;
    int src, dest;
};

bool compare(const edge& a, const edge& b) {
    return a.weight < b.weight;
}

class DisjointSet {
    public:
        vector<int> parent;
        vector<int> rank;

        DisjointSet(int N) : parent(N), rank(N) {
            for (int i = 0; i < N; i++) {
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
            
            if (rootA == rootB) return true;
            else {
                if (rank[rootA] > rank[rootB]) {
                    parent[rootB] = rootA;
                } else if (rank[rootB] > rank[rootA]) {
                    parent[rootA] = rootB;
                } else {
                    rank[rootA]++;
                    parent[rootB] = rootA;
                }
            }
            return false;
        }

        double Kruskal(int N, vector<edge>& Edges) {
            double totalCost = 0;
            sort(Edges.begin(), Edges.end(), compare);
            for (const auto& edge : Edges) {
                if (findRoot(edge.src) != findRoot(edge.dest)) {
                    unionSet(edge.src, edge.dest);
                    totalCost += edge.weight;
                }
            }
            return totalCost;
        }
};

void testcase() {
    int N;
    cin >> N;

    vector<pair<double, double>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first;
        cin >> points[i].second;
    }

    vector<edge> Edges;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            double dist = sqrt(pow(abs(points[i].first - points[j].first), 2) + pow(abs(points[i].second - points[j].second), 2));
            Edges.push_back({dist, i, j});
        }
    }
    DisjointSet a(N);
    cout << fixed << setprecision(6) << a.Kruskal(N, Edges) << '\n';
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
//NỐI ĐIỂM