//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>

using namespace std;

string toGray(const string& binary) {
    string gray = binary.substr(0, 1);
    for (int i = 1; i < binary.size(); i++) {
        gray += (binary[i - 1] == binary[i]) ? '0' : '1';
    }
    return gray;
}

void testcase() {
    string binary; cin >> binary;
    cout << toGray(binary) << endl;
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
//MÃ GRAY 3

