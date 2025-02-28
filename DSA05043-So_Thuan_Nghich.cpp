//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/10/2024

#include <iostream>
#include <vector>

//Fear is just an illusion

using namespace std;

void testcase() {
    string S; 
    cin >> S;
    int N = S.size();

    vector<vector<bool>> dp(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        dp[i][i] = true;
    }

    int maxLength = 1;

    for (int i = 0; i < N - 1; i++) {
        if (S[i] == S[i + 1]) {
            dp[i][i + 1] = true;
            maxLength = 2;
        }
    }

    for (int length = 3; length <= N; length++) {
        for (int i = 0; i < N - length + 1; i++) {
            int j = i + length - 1;
            if (S[i] == S[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                maxLength = length;
            }
        }
    }

    cout << maxLength << '\n';
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
//SỐ THUẬN NGHỊCH