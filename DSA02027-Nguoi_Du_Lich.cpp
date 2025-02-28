//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 28/09/2024

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct City {
    vector<vector<int>> distance;
    vector<bool> visited;
    vector<int> path;
    int nearest;

    City(int n) : distance(n, vector<int>(n)), visited(n, false), nearest(INT_MAX), path(1, 0) {}
};

void findNearest(City &a, int currentExpense) {
    if (currentExpense > a.nearest) {
        return;
    }
    if (a.path.size() == a.distance.size()) {
        if (currentExpense + a.distance[0][a.path.back()] < a.nearest) {
            a.nearest = currentExpense + a.distance[0][a.path.back()];
        }
        return;
    }
    for (size_t i = 1; i < a.distance.size(); i++) {
        if (!a.visited[i]) {
            a.visited[i] = true;
            int newExpense = currentExpense + a.distance[i][a.path.back()];
            a.path.push_back(i);
            findNearest(a, newExpense);
            a.visited[i] = false;
            a.path.pop_back();
        }
    }
}

void solve() {
    int n; cin >> n;
    City a(n);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cin >> a.distance[i][j];
        }
    }
    findNearest(a, 0);
    cout << a.nearest << endl;
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//NGƯỜI DU LỊCH