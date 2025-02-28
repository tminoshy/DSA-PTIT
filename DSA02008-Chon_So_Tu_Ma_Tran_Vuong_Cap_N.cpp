//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 06/10/2024

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Matrix {
    vector<vector<int>> numbers;
    vector<int> currentPermutation;
    vector<vector<int>> result;

    Matrix(int N) : numbers(N, vector<int>(N)), currentPermutation(N) {}
};

void generatePermutations(int index, int N, int targetSum, Matrix& a) {
    if (index == N) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += a.numbers[i][a.currentPermutation[i]];
        }
        if (sum == targetSum) {
            a.result.push_back(a.currentPermutation);
        }
        return;
    }
    for (int i = index; i < N; i++) {
        swap(a.currentPermutation[index], a.currentPermutation[i]);
        generatePermutations(index + 1, N, targetSum, a);
        swap(a.currentPermutation[index], a.currentPermutation[i]);
    }
}

void solve() {
    int N, K;
    cin >> N >> K;
    Matrix a(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a.numbers[i][j];
        }
    }
    iota(a.currentPermutation.begin(), a.currentPermutation.end(), 0);
    generatePermutations(0, N, K, a);
    cout << a.result.size() << endl;
    for (const vector<int>& vec : a.result) {
        for (const int& value : vec) {
            cout << value + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//CHỌN SỐ TỪ MA TRẬN VUÔNG CẤP N