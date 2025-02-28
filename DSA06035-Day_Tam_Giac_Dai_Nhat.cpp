//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 02/10/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    vector<int> dpI(N, 1), dpD(N, 1);
    for (int i = 1; i < N; i++) {
        if (numbers[i] > numbers[i - 1]) {
            dpI[i] = dpI[i - 1] + 1;
        }
    }
    for (int i = N - 2; i >= 0; i--) {
        if (numbers[i] > numbers[i + 1]) {
            dpD[i] = dpD[i + 1] + 1;
        }
    }
    int maxLength = 0;
    for (int i = 0; i < N; i++) {
        maxLength = max(maxLength, (dpI[i] + dpD[i] - 1));
    }
    cout << maxLength << endl;
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
//DSA06035