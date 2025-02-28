//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/09/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int M, N, K;
    cin >> M >> N >> K;
    vector<int> vecM(M), vecN(N);
    for (int& value : vecM) {
        cin >> value;
    }
    for (int& value : vecN) {
        cin >> value;
    }
    int count = 0;
    int indexM = 0, indexN = 0;
    int currentValue;
    for (size_t i = 0; i < K; i++) {
        if (indexM < M && (indexN >= N || vecM[indexM] <= vecN[indexN])) {
            currentValue = vecM[indexM];
            indexM++;
        } else {
            currentValue = vecN[indexN];
            indexN++;
        }
    }
    cout << currentValue << endl;
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
//PHẦN TỬ THỨ K