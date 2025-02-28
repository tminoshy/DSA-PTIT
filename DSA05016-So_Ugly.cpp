//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 08/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase() {
    int N;
    cin >> N;
    vector<long long> dp(N);
    dp[0] = 1;

    long long next2 = 2, next3 = 3, next5 = 5;
    int i2 = 0, i3 = 0, i5 = 0;

    for (int i = 1; i < N; i++) {
        long long newUgly = min(next2, min(next3, next5));
        dp[i] = newUgly;
        if (newUgly == next2) {
            i2++;
            next2 = dp[i2] * 2;
        }
        if (newUgly == next3) {
            i3++;
            next3 = dp[i3] * 3;
        }
        if (newUgly == next5) {
            i5++;
            next5 = dp[i5] * 5;
        }
    }
    
    cout << dp[N - 1] << '\n';
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
//SỐ UGLY