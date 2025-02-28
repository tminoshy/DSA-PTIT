//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/09/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> track(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int value; cin >> value;
        track[value] = track[value - 1] + 1;
    }
    cout << n - *max_element(track.begin() + 1, track.end());
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//SẮP XẾP ĐƠN GIẢN