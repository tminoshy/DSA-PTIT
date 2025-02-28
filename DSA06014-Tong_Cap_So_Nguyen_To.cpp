//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 19/08/2024

#include <iostream>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number <= 3) {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void Testcase() {
    int number;
    cin >> number;

    for (int i = 0; i <= number / 2; i++) {
        if (isPrime(i) && isPrime(number - i)) {
            cout << i << " " << number - i << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    int testCount;
    cin >> testCount;

    while (testCount--) {
        Testcase();
    }
    
    return 0;
}

//B23DCCE064
//TỔNG CẶP SỐ NGUYÊN TỐ