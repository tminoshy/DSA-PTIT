//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 02/10/2024

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

void testcase() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            double c = pow(numbers[i], 2) + pow(numbers[j], 2);
            long long sqrtC = static_cast<long long>(sqrt(c));
            if (c - sqrtC * sqrtC == 0) {
                auto it = find(numbers.begin() + j + 1, numbers.end(), sqrtC);
                    if (it != numbers.end()) {
                        cout << "YES\n";
                        return;
                    }
            }
        }
    }
    cout << "NO\n";
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
//BỘ BA SỐ PYTAGO