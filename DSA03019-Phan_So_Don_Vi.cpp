//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 07/10/2024

#include <iostream>

using namespace std;


//2/3
//1/2


void testcase() {
    long long P, Q;
    cin >> P >> Q;
    while (true) {
        if (Q % P == 0) {
            cout << "1/" << Q / P << endl;
            break;
        } else {
            int x = Q / P + 1;
            cout << "1/" << x << " + ";
            P = P * x - Q;
            Q *= x;
        }
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

//B23DCCE064
//PHÂN SỐ ĐƠN VỊ