//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 09/10/2024

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> Matrix;

const int MOD = 1e9 + 7;

Matrix matrixMultiple(const Matrix &a, const Matrix &b) {
    return {
        {(a[0][0] * b[0][0] % MOD + a[0][1] * b[1][0] % MOD) % MOD, 
         (a[0][0] * b[0][1] % MOD + a[0][1] * b[1][1] % MOD) % MOD},
        {(a[1][0] * b[0][0] % MOD + a[1][1] * b[1][0] % MOD) % MOD,
         (a[1][0] * b[0][1] % MOD + a[1][1] * b[1][1] % MOD) % MOD} 
    };
}

Matrix matrixPow(Matrix &mat, int exponent) {
    Matrix res = {{1, 0}, {0, 1}};
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            res = matrixMultiple(res, mat);
        }
        mat = matrixMultiple(mat, mat);
        exponent /= 2;
    }
    return res;
}

void testcase() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << "0\n";
        return;
    }
    if (N == 1) {
        cout << "1\n";
        return;
    }
    Matrix F = {{1, 1}, {1, 0}};
    Matrix result = matrixPow(F, N - 1);
    cout << result[0][0] << '\n';
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
//SỐ FIBONACCI THỨ N