//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 07/10/2024

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N, S;
    cin >> N >> S;
    if (S > N * 9 || S == 0) {
        cout << "-1 -1\n";
        return;
    }
    vector<int> biggest(N, 0);
    vector<int> smallest(N, 0);
    int remain = S;
    for (int i = 0; i < N; i++) {
        if (remain > 9) {
            biggest[i] = 9;
            remain -= 9;
        } else {
            biggest[i] = remain;
            break;
        }
    }
    remain = S;
    int index = smallest.size() - 1;
    while (remain > 0) {
        if (remain > 9) {
            smallest[index] = 9;
            remain -= 9;
        } else {
            smallest[index] = remain;
            remain = 0;
        }
        index--;
    }
    if (smallest[0] == 0) {
        smallest[0] = 1;
        smallest[index + 1] -= 1;
    }
    for (const int& value : smallest) {
        cout << value;
    }
    cout << " ";
    for (const int& value : biggest) {
        cout << value;
    }
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//LỰA CHỌN THAM LAM