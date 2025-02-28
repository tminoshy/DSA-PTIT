//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 01/10/2024

#include <iostream>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;

struct Matrix {
    vector<vector<long long>> matrix;
    int N;

    Matrix(int size) : N(size), matrix(size, vector<long long>(size, 0)) {}

    friend Matrix operator* (const Matrix& x, const Matrix& y) {
        Matrix result(x.N);
        for (size_t i = 0; i < x.N; i++) {
            for (size_t j = 0; j < y.N; j++) {
                for (size_t k = 0; k < x.N; k++) {
                    result.matrix[i][j] = (result.matrix[i][j] + (x.matrix[i][k] * y.matrix[k][j]) % MOD) % MOD;
                }
            }
        }
        return result;
    }
};

Matrix binaryPow(Matrix A, int K) {
    if (K == 1) return A;
    Matrix x = binaryPow(A, K / 2);
    if (K % 2 == 0) return x * x;
    return x * x * A;
}

void testcase() {
    int N, K;
    cin >> N >> K;
    Matrix A(N);
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cin >> A.matrix[i][j];
        }
    }
    Matrix result = binaryPow(A, K);
    long long sum = 0;
    for (size_t i = 0; i < N; i++) {
        sum = (sum + result.matrix[i][N - 1]) % MOD;
    }
    cout << sum << endl;
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
//LŨY THỪA MA TRẬN 2