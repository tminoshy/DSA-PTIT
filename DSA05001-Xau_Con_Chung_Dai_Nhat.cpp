//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 01/10/2024

#include <iostream>
#include <vector>

using namespace std;

int longestCommonSequence(const string& S1, const string& S2) {
    int size1 = S1.size();
    int size2 = S2.size();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
    for (size_t i = 1; i <= size1; i++) {
        for (size_t j = 1; j <= size2; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[size1][size2];
}

void testcase() {
    string S1, S2;
    cin >> S1 >> S2;
    cout << longestCommonSequence(S1, S2) << endl;
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
//XÂU CON CHUNG DÀI NHẤT