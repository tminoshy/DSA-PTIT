//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 16/09/2024

#include <iostream>
#include <vector>

using namespace std;

void generateBinaryString(int index, int sz, int currentSum, int targetSum, vector<int>& binary) {
    if (currentSum > targetSum) return;
    if(index == sz) {
        if (currentSum == targetSum) {
            for (const int &value : binary) {
                cout << value;
            }
            cout << endl;
        }
        return;
    }
    binary[index] = 0;
    generateBinaryString(index + 1, sz, currentSum, targetSum, binary);
    binary[index] = 1;
    generateBinaryString(index + 1, sz, currentSum + 1, targetSum, binary);
}

void Testcase() {
    int N, total; 
    cin >> N >> total;
    vector<int> binarystring(N);
    generateBinaryString(0, N, 0, total, binarystring);
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//B23DCCE064
//XÂU NHỊ PHÂN CÓ K BIT 1