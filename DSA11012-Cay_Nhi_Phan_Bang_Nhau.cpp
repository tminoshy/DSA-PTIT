//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 14/10/2024

#include <iostream>

using namespace std;

void testcase() {
    int N;
    cin >> N;

    cin.ignore();
    string s1;
    getline(cin, s1);

    cin >> N;

    cin.ignore();
    string s2;
    getline(cin, s2);

    if (s1 != s2) {
        cout << "0" << '\n';
    } else {
        cout << "1" << '\n';
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
//CÂY NHỊ PHÂN BẰNG NHAU