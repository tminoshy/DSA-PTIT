//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 27/10/2024

#include <iostream>
#include <algorithm>

using namespace std;

//Fear is just an illusion

void solve() {
    string S;
    cin >> S;
    
    int N;
    cin >> N;
    while (N--) {
        char x;
        int a, b;
        cin >> x >> a >> b;
        if (x == 'q') {
            bool isPalindrome = true;
            for (int i = 0; i < (b - a + 1) / 2; ++i) {
                if (S[a - 1 + i] != S[b - 1 - i]) {
                    isPalindrome = false;
                    break;
                }
            }
            if (isPalindrome) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        } else if (x == 'c') {
            S[a - 1] = b + '0';
        }
    }
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//TRUY VẤN ĐỐI XỨNG