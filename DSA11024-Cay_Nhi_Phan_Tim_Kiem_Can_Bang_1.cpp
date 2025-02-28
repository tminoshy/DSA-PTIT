//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 15/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase() {
    int N;
    cin >> N;

    vector<int> nodeVal(N);
    for (int &value : nodeVal) {
        cin >> value;
    }

    sort(nodeVal.begin(), nodeVal.end());

    cout << nodeVal[(N - 1) >> 1] << '\n';
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
//CÂY NHỊ PHÂN TÌM KIẾM CÂN BẰNG 1