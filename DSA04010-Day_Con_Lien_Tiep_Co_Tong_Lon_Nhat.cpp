//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/09/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    int currentSum = 0, maxSum = 0;
    for (size_t i = 0; i < N; i++) {
        currentSum += numbers[i];
        if (currentSum < 0) currentSum = 0;
        maxSum = max(currentSum, maxSum);
    }
    cout << maxSum << endl;
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
//DÃY CON LIÊN TIẾP CÓ TỔNG LỚN NHẤT