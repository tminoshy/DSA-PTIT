//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 09/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase() {
    int n, k;
    cin >> n >> k;
    vector<int> numbers(n);

    for (int &value : numbers) {
        cin >> value;
    }

    sort(numbers.begin(), numbers.end());

    long long ans = 0;

    for (int i = 0; i < n - 1; i++) {
        auto it = upper_bound(numbers.begin() + i, numbers.end(), k + numbers[i] - 1);
        ans += (it - numbers.begin() - i - 1);
    }

    cout << ans << '\n';
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
//KHOẢNG CÁCH NHỎ HƠN K