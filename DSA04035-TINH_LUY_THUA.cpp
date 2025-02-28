//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 27/09/2024

#include <iostream>

using namespace std;

long long MOD = 1e9 + 7;

long long binaryExponentiation(long long base, long long exponent) {
    if (exponent == 0) return 1;
    long long x = binaryExponentiation(base, exponent / 2);
    if (exponent % 2 == 0) return (x * x) % MOD;
    return (((x * x) % MOD) * base) % MOD;
}

void solve() {
    string number1, number2;
    while (cin >> number1 >> number2) {
        if (number1 == "0" && number2 == "0") return;
        cout << binaryExponentiation(stoll(number1), stoll(number2)) << endl;
    }
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//TÍNH LŨY THỪA