//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> odd, even;
    for(int i = 1; i <= n; i++) {
        int value; cin >> value;
        if(i % 2 == 0) {
            even.push_back(value);
        } else {
            odd.push_back(value);
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.rbegin(), even.rend());
    for(int i = 0; i < even.size(); i++) {
        cout << odd[i] << " " << even[i] << " ";
    }
    if(n % 2 != 0) {
        cout << odd.back();
    }
}

int main() {
    solve();
    return 0;
}

//