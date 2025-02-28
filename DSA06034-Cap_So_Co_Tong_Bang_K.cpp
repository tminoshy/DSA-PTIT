//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 02/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase() {
    int N, K;
    cin >> N >> K;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    sort(numbers.begin(), numbers.end());
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += (upper_bound(numbers.begin() + i + 1, numbers.end(), K - numbers[i]) - lower_bound(numbers.begin() + i + 1, numbers.end(), K - numbers[i]));
    }
    cout << ans << endl;
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
//CẶP SỐ CÓ TỔNG BẰNG K