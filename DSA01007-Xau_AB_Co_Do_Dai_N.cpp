//https://github.com/tminoshy
//created by Đỗ Thiện Minh at 16/09/2024

#include <iostream>
#include <vector>

using namespace std;

void generateAB(int index, int sz, vector<char>& stringAB) {
    if (index == sz) {
        for (const char &alpha : stringAB) {
            cout << alpha;
        }
        cout << " ";
        return;
    }
    stringAB[index] = 'A';
    generateAB(index + 1, sz, stringAB);
    stringAB[index] = 'B';
    generateAB(index + 1, sz, stringAB);
}

void Testcase() {
    int n; cin >> n;
    vector<char> stringAB(n);
    generateAB(0, n, stringAB);
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
//XÂU AB CÓ ĐỘ DÀI N