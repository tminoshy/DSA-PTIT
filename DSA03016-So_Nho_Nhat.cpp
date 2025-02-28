//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <vector>   

using namespace std;

void testcase() {
    int S, D;
    cin >> S >> D;
    if (S > 9 * D) {
        cout << "-1\n";
        return;
    }
    vector<int> number(D, 0);
    int index = D - 1;
    while (S > 0) {
        if (S > 9) {
            number[index] = 9;
            S -= 9;
        } else {
            number[index] = S;
            S = 0;
        }
        index--;
    }
    if (number[0] == 0) {
        number[0] = 1;
        number[index + 1] -= 1;
    }
    for (int digit : number) {
        cout << digit;
    }
    cout << endl;
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
//SỐ NHỎ NHẤT