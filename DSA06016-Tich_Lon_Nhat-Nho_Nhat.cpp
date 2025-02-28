//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 14/08/2024

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void Testcase() {
    int size1, size2;
    cin >> size1 >> size2;

    vector<int> myVec1(size1);
    vector<int> myVec2(size2);

    int maxElement1 = INT_MIN;

    for (int i = 0; i < size1; i++) {
        cin >> myVec1[i];
        if (myVec1[i] > maxElement1) {
            maxElement1 = myVec1[i];
        }
    }

    int minElement2 = INT_MAX;

    for (int i = 0; i < size2; i++) {
        cin >> myVec2[i];
        if (myVec2[i] < minElement2) {
            minElement2 = myVec2[i];
        }
    }

    cout << static_cast<long long>(maxElement1) * minElement2 << '\n';
}

int main() {
    int testCount;
    cin >> testCount;

    while (testCount--) {
        Testcase();
    }

    return 0;
}

//B23DCCE064
//TÍCH LỚN NHẤT - NHỎ NHẤT