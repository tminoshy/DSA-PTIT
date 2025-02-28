//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 27/09/2024

#include <iostream>

using namespace std;

int MOD = 123456789;

long long binaryExponentiation(long base, long long exponent) {
    if (exponent == 0) return 1;
    long long x = binaryExponentiation(base, exponent / 2);
    if (exponent % 2 == 0) return (x * x) % MOD;
    return (((x * x) % MOD) * base) % MOD;
}

void testcase() {
    long long n; cin >> n;
    cout << binaryExponentiation(2, n - 1) << endl;
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
//ĐẾM DÃY