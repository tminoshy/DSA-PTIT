//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 07/10/2024

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void backtrack(int index, const vector<int>& money, int current, int& ans, int remain) {
    if (index == money.size() || remain <= 0 || current > ans) {
        if (remain == 0) {
            ans = min(ans, current);
        }
        return;
    }
    backtrack(index + 1, money, current + 1, ans, remain - money[index]);
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
    solve();
    return 0;
}

//B23DCCE064
//ĐỔI TIỀN