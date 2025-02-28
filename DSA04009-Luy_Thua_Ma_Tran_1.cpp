//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 04/10/2024

#include <iostream>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;

struct Matrix {
    vector<vector<long long>> matrix;

    Matrix(int N) : matrix(N, vector<long long>(N, 0)) {}

    Matrix operator* (const Matrix& others) {
        int N = matrix.size();
        Matrix result(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    result.matrix[i][j] = (result.matrix[i][j] + (this->matrix[i][k] * others.matrix[k][j]) % MOD) % MOD;
                }
            }
        }
        return result;
    }
};

Matrix binaryPow(int K, const Matrix& a) {
    if (K == 1) return a;
    Matrix x = binaryPow(K / 2, a);
    if (K % 2 == 0) return x * x;
    return x * x * a;
}

void testcase() {
    int N, K;
    cin >> N >> K;
    Matrix a(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a.matrix[i][j];
        }
    }
    Matrix ans = binaryPow(K, a);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans.matrix[i][j] << " ";
        }
        cout << endl;
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
//LŨY THỪA MA TRẬN 1