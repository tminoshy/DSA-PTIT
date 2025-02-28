//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 01/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase() {
    int N; cin >> N;
    vector<pair<int, int>> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i].first;
        numbers[i].second = i;
    }
    sort(numbers.begin(), numbers.end());
    int minIndex = numbers[0].second;
    int ans = -1;
    int currentVal = numbers[0].first;
    for (int i = 1; i < N; i++) {
        if (numbers[i].first > currentVal)
        ans = max(ans, numbers[i].second - minIndex);
        if (minIndex > numbers[i].second) {
            minIndex = numbers[i].second;
            currentVal = numbers[i].first;
        }
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
//KHOẢNG CÁCH XA NHẤT