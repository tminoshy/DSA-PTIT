//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 08/10/2024

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void backtrack(int index, const vector<int>& money, int current, int& ans, int remain) {
    // Base case: if we have considered all banknotes or the remaining amount is zero or current count exceeds the best answer
    if (index == money.size() || remain <= 0 || current > ans) {
        if (remain == 0) {
            ans = min(ans, current);
        }
        return;
    }
    // Include the current banknote and move to the next
    backtrack(index + 1, money, current + 1, ans, remain - money[index]);
    // Exclude the current banknote and move to the next
    backtrack(index + 1, money, current, ans, remain);
}

void solve() {
    int n, S;
    cin >> n >> S;
    vector<int> money(n);
    for (int& value : money) {
        cin >> value;
    }
    sort(money.rbegin(), money.rend());
    int ans = INT_MAX;
    backtrack(0, money, 0, ans, S);
    cout << (ans == INT_MAX ? -1 : ans) << endl;
}

int main() {
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

//B23DCCE064
//MÁY ATM