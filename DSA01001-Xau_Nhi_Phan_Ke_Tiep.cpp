//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 14/08/2024

#include <iostream>
#include <vector>

using namespace std;

void Testcase() {
    string X; cin >> X;
    vector<int> binaryDigits;
    for (size_t i = 0; i < X.size(); i++) {
        binaryDigits.push_back(X[i] - '0');
    }
    int index = X.size() - 1;
    while (index >= 0 && binaryDigits[index] == 1) {
        binaryDigits[index--] = 0;
    }
    if (index >= 0) {
        binaryDigits[index] = 1;
    }
    if (index < 0) {
        for (size_t i = 0; i < binaryDigits.size(); i++) {
            cout << "0";
        }
    } else {
        for (size_t i = 0; i < binaryDigits.size(); i++)  {
            cout << binaryDigits[i];
        }
    }
    cout << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//B23DCCE064
//XÂU NHỊ PHÂN KẾ TIẾP