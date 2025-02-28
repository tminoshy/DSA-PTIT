//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 01/10/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int N, S;
    cin >> N >> S;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    vector<bool> dp(S + 1);
    dp[0] = true;
    for (const int& value : numbers) {
        for (int j = S; j >= value; j--) {
            if (dp[j - value]) {
                dp[j] = true;
            }
        }
    }
    if (dp[S]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
//DÃY CON CÓ TỔNG BẰNG S