//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 17/09/2024

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calculateCombineNumber(int N, int K, vector<int>& currentCombination, vector<int> targetCombination) {
    int count = 1;
    while (!equal(currentCombination.begin(), currentCombination.end(), targetCombination.begin())) {
        count++;
        int i = K - 1;
        while (i >= 0 && currentCombination[i] == N - K + i + 1) {
            i--;
        }
        if (i >= 0) {
            currentCombination[i]++;
        }
        for (int j = i + 1; j < K; j++) {
            currentCombination[j] = currentCombination[i] - i + j;
        }
    }
    return count;
}

void Testcase() {
    int N, K;
    cin >> N >> K;
    vector<int> targetCombination(K);
    for (int &value : targetCombination) {
        cin >> value;
    }
    vector<int> currentCombination(K);
    for (size_t i = 0; i < K; i++) {
        currentCombination[i] = i + 1;
    }
    cout << calculateCombineNumber(N, K, currentCombination, targetCombination) << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//B23DCCE064
//SỐ THỨ TỰ TỔ HỢP