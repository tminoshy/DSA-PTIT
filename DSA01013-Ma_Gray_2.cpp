//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>

using namespace std;

string grayToBinary(const string& gray) {
    string binary = gray.substr(0, 1);
    for (int i = 1; i < gray.size(); i++) {
        binary += (gray[i] == '1') ? (binary[i - 1] == '1' ? '0' : '1') : binary[i - 1];
    }
    return binary;
}

void testcase() {
    string s; cin >> s;
    cout << grayToBinary(s) << endl;
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
//MÃ GRAY 2