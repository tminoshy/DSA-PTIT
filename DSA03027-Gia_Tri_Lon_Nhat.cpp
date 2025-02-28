//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 21/10/2024

#include <iostream>

using namespace std;

//Fear is just an illusion

void solve() {
    int N;
    cin >> N;
    long long ans = 0;

    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        ans += (value > 0) ? value * 2 : 0;
    }

    cout << ans;
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//GIÁ TRỊ LỚN NHẤT