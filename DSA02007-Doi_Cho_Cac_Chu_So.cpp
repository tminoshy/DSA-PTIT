//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 26/09/2024

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void findMax(string &S, int K, string &maxValue) {
    if (K == 0) {
        return;
    }
    for (size_t i = 0; i < S.size() - 1; i++) {
        for (size_t j = i + 1; j < S.size(); j++) {
            if (S[i] < S[j]) {
                swap(S[i], S[j]);
                if (S.compare(maxValue) > 0) {
                    maxValue = S;
                }
                findMax(S, K - 1, maxValue);
                swap(S[i], S[j]);
            }
        }
    }
}

void testcase() {
    int K; cin >> K;
    string S; cin >> S;
    string maxValue = S;
    findMax(S, K, maxValue);
    cout << maxValue << endl;
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
//ĐỔI CHỖ CÁC CHỮ SỐ