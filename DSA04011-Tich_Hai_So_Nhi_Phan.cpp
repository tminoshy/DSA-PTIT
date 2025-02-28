//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 09/10/2024

#include <iostream>

using namespace std;

long long toDecimal(const string& binary) {
    long long decimal = 0;
    
    for (const char &c : binary) {
        decimal = decimal * 2 + (c - '0');
    }

    return decimal;
}

void testcase() {
    string S1, S2;
    cin >> S1 >> S2;

    cout << toDecimal(S1) * toDecimal(S2) << '\n';
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
//TÍCH HAI SỐ NHỊ PHÂN