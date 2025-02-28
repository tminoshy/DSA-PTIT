//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 09/10/2024

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void testcase() {
    int M, N;
    cin >> M >> N;
    vector<int> P(M);
    vector<int> Q(N);

    for (int i = 0; i < M; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> Q[i];
    }

    unordered_map<int, int> umap;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            umap[i + j] += P[i] * Q[j]; 
        }
    }

    vector<pair<int, int>> ans(umap.begin(), umap.end());
    sort(ans.begin(), ans.end());
    
    for (const pair<int, int> &value : ans) {
        cout << value.second << " ";
    }
    cout << '\n';
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
//TÍCH ĐA THỨC