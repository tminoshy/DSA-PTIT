//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 09/10/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int N;
    cin >> N;
    vector<int> numbers(N);

    for (int &value : numbers) {
        cin >> value;
    }

    vector<int> dpIncrease(N, 1);

    for (int i = 1; i < N; i++) {
        if (numbers[i] > numbers[i - 1]) {
            dpIncrease[i] = dpIncrease[i - 1] + 1;
        }
    }

    vector<int> dpDecrease(N, 1);

    for (int i = N - 2; i >= 0; i--) {
        if (numbers[i] > numbers[i + 1]) {
            dpDecrease[i] = dpDecrease[i + 1] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, dpIncrease[i] + dpDecrease[i] - 1);
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
//DÃY TAM GIÁC DÀI NHẤT