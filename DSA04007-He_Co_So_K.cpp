//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 08/10/2024

#include <iostream>

using namespace std;

long long toDecimal(const string& str, int base) {
    long long result = 0;
    for (int i = 0; i < str.size(); i++) {
        result = result * base + (str[i] - '0');
    }
    return result;
}

string toBaseK(long long number, int base) {
    if (number == 0) {
        return "0";
    }
    string result = "";
    while (number > 0) {
        result = static_cast<char>((number % base) + '0') + result;
        number /= base;
    }
    return result;
}

void testcase() {
    int K;
    string A, B;
    cin >> K >> A >> B;

    long long decimalA = toDecimal(A, K);
    long long decimalB = toDecimal(B, K);

    long long sum = decimalA + decimalB;

    string result = toBaseK(sum, K);

    cout << result << '\n';
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
//HỆ CƠ SỐ K