//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>

using namespace std;

int MOD = 1e9 + 7;

long long binaryExponentiation(int base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    long long x = binaryExponentiation(base, exponent / 2);
    long long y = (x * x) % MOD;
    if (exponent % 2 == 0) {
        return y;
    }
    return base * y % MOD;
}

void testcase() {
    int N, K;
    cin >> N >> K;
    cout << binaryExponentiation(N, K) << endl;
}

int main() {
    int testCaseCount;
    cin >> testCaseCount;
    while (testCaseCount--) {
        testcase();
    }
    return 0;
}

//LŨY THỪA