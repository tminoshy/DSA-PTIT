//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/10/2024

#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

//Fear is just an illusion

void Floyd(int N, vector<vector<long long>>& distance) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
}

double calculateAveragePath(int N, vector<vector<long long>>& distance) {
    double totalPath = 0.0;
    int count = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j && distance[i][j] < INT_MAX) {
                totalPath += distance[i][j];
                count++;
            }
        }
    }

    if (count == 0) return 0.00;
    return totalPath / count;
}

void testcase() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<long long>> distance(N + 1, vector<long long>(N + 1, INT_MAX));
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        distance[u][v] = 1;
    }

    for (int i = 1; i <= N; i++) {
        distance[i][i] = 0;
    }

    Floyd(N, distance);

    cout << fixed << setprecision(2) << calculateAveragePath(N, distance) << '\n';
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
//ĐƯỜNG ĐI TRUNG BÌNH