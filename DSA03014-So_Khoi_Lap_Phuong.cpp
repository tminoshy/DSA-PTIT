//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 21/10/2024

#include <iostream>
#include <cmath>

using namespace std;

//Fear is just an illusion

bool valid(string s) {
    long long root = round(cbrt(stoll(s)));
    return root * root * root == stoll(s);
}

void findLargestCubic(int index, const string& number, string current, long long& maxCubic) {
    if (index == number.size()) {
        if (current.size() > 0) {
            if (valid(current)) {
                maxCubic = max(maxCubic, stoll(current));
            }
        }
        return;
    }

    findLargestCubic(index + 1, number, current + number[index], maxCubic);
    findLargestCubic(index + 1, number, current, maxCubic);
}

void testcase() {
    string number;
    cin >> number;
    long long maxCubic = -1;
    findLargestCubic(0, number, "", maxCubic);

    cout << maxCubic << '\n';
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
//SỐ KHỐI LẬP PHƯƠNG