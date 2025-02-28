//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 19/09/2024

#include <iostream>

using namespace std;

int to_5(string number) {
    int numberto5 = 0;
    for (int i = 0; i < number.size(); i++) {
        char digit = number[i];
        if (digit == '6') {
            digit = '5';
        }
        numberto5 = numberto5 * 10 + (digit - '0');
    }
    return numberto5;
}

int to_6(string number) {
    int numberto6 = 0;
    for (int i = 0; i < number.size(); i++) {
        char digit = number[i];
        if (digit == '5') {
            digit = '6';
        }
        numberto6 = numberto6 * 10 + (digit - '0');
    }
    return numberto6;
}


void solve() {
    string number1, number2;
    cin >> number1 >> number2;
    cout << to_5(number1) + to_5(number2) << " " << to_6(number1) + to_6(number2);
}

int main() {
    solve();
    return 0;
}

//NHẦM CHỮ SỐ