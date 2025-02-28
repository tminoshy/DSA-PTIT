//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 02/10/2024

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void testcase() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    sort(numbers.begin(), numbers.end());
    int minDiff = INT_MAX;
    for (int i = 1; i < N; i++) {
        minDiff = min(minDiff, numbers[i] - numbers[i - 1]);
    }
    cout << minDiff << endl;
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
//CHÊNH LỆCH NHỎ NHẤT