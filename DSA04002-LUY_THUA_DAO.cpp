//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 27/09/2024

#include <iostream>
#include <algorithm>

using namespace std;

long long MOD = 1e9 + 7;

long long binaryExponentiation(long long base, long long Exponent) {
    if (Exponent == 0) return 1;
    long long x = binaryExponentiation(base, Exponent / 2);
    if (Exponent % 2 == 0) return (x * x) % MOD;
    return (((x * x) %  MOD) * base) % MOD;
}

void testcase() {
    string N; cin >> N;
    string R = N;
    reverse(R.begin(), R.end());
    cout << binaryExponentiation(stoll(N), stoll(R)) << endl;
}

int main() {
    int testCaseCount;
    cin >> testCaseCount;
    while (testCaseCount--) {
        testcase();
    }
    return 0;
}

//LŨY THỪA ĐẢO