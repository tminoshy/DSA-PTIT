//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 27/09/2024

#include <iostream>
#include <cmath>

using namespace std;

void testcase() {
    int N, S, M;
    cin >> N >> S >> M;
    int require = ceil((S * M) / static_cast<double>(N));
    if (require <= S - S / 7) {
        cout << require << endl;
    } else {
        cout << "-1\n";
    }
}

int main() {
    int testCaseCount;
    cin >> testCaseCount;
    while (testCaseCount--) {
        testcase();
    }
    return 0;
}

//MUA LƯƠNG THỰC