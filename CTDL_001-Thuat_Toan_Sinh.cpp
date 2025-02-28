//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 13/08/2024

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void generatePalindromeBinaryStrings(const int index, const int halfSize, vector<int> &binary) {
    if (index == halfSize) {
        for (const size_t &value : binary) {
            cout << value << " ";
        }
        for (int i = halfSize - 1; i >= 0; i--) {
            cout << binary[i] << " ";
        }
        cout << endl;
        return;
    }
    for (size_t i = 0; i <= 1; i++) {
        binary.push_back(i);
        generatePalindromeBinaryStrings(index + 1, halfSize, binary);
        binary.pop_back();
    }
}

void solve() {
    int n; cin >> n;
    int halfSize = n / 2;
    vector<int> binary;
    generatePalindromeBinaryStrings(0, halfSize, binary);
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//Thuật toán sinh