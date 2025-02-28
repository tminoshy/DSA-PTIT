//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 08/10/2024

#include <iostream>

using namespace std;

void solve() {
    int N; cin >> N;
    string S; 
    cin >> S;
    
    int countX = 0, countD = 0;
    
    for (const char &c : S) {
        if (c == 'X') {
            countX++;
        } else if (c == 'D') {
            countD++;
        }
    }
    
    int misplace = 0, countDInX = 0, countXInD = 0; // Red in blue place and blue in red place;
    
    for (int i = 0; i < countX; i++) {
        if (S[i] != 'X') {
            misplace++;
            if (S[i] == 'D') {
                countDInX++;
            }
        }
    }
    
    for (int i = S.size() - 1; i >= S.size() - countD; i--) {
        if (S[i] != 'D') {
            misplace++;
            if (S[i] == 'X') {
                countXInD++;
            }
        }
    }
    
    /*For instance, if we have the string 'XDXD', there are two mismatches: 
    one 'D' is in the position where there should be an 'X', 
    and one 'X' is in the position where there should be a 'D'. 
    By swapping these two characters, we can correct both mismatches at once, 
    meaning that just one swap is enough*/
    cout << misplace - min(countXInD, countDInX);
}

int main() {
    solve();

    return 0;
}

//B23DCCE064
//SẮP XẾP VIÊN BI