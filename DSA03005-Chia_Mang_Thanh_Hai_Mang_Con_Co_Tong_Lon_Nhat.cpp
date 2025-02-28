//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/09/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase() {
    int N, K;
    cin >> N >> K;
    vector<int> numbers(N);
    int sum = 0;
    for (int &value : numbers) {
        cin >> value;
        sum += value;
    }
    sort(numbers.begin(), numbers.end());
    K = min(K, N - K);
    for (size_t i = 0; i < K; i++) {
        sum -= 2 * numbers[i];
    }
    cout << sum << endl;
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
//CHIA MẢNG THÀNH HAI MẢNG CON CÓ TỔNG LỚN NHẤT