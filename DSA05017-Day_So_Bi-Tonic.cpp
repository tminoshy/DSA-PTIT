//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase() {
    int N; 
    cin >> N;
    vector<int> numbers(N);

    for (int &value : numbers) {
        cin >> value;
    }

    vector<int> dpIncrease(N, 0);
    vector<int> dpDecrease(N, 0);

    for (int i = 0; i < N; i++) {
        dpIncrease[i] = numbers[i];
        for (int j = 0; j < i; j++) {
            if (numbers[j] < numbers[i]) {
                dpIncrease[i] = max(dpIncrease[i], dpIncrease[j] + numbers[i]);
            }
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        dpDecrease[i] = numbers[i];
        for (int j = N - 1; j > i; j--) {
            if (numbers[j] < numbers[i]) {
                dpDecrease[i] = max(dpDecrease[i], dpDecrease[j] + numbers[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, dpIncrease[i] + dpDecrease[i] - numbers[i]);
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
//DÃY SỐ BI-TONIC