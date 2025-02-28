//https://github.com/tminoshy
//created by Đỗ Thiện Minh at 16/09/2024

#include <iostream>

using namespace std;

void previousBinaryString(int index, string &binary) {
    if (index < 0) {
        cout << binary << endl;
        return;
    }
    if (binary[index] == '1') {
        binary[index] = '0';
        cout << binary << endl;
        return;
    }
    binary[index] = '1';
    previousBinaryString(index - 1, binary);
}

void Testcase() {
    string X; cin >> X;
    previousBinaryString(X.size() - 1, X);
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//B23DCCE064
//XÂU NHỊ PHÂN TRƯỚC