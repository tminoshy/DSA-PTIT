//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 07/10/2024

#include <iostream>

using namespace std;

void testcase() {
    int n; cin >> n;
    int count4 = 0, count7 = 0;
    bool found = false;
    for (int i = 0; i <= n / 4; i++) {
        if ((n - 4 * i) % 7 == 0) {
            count4 = i;
            count7 = (n - 4 * i) / 7;
            found = true;
            break;
        } 
    }
    if (!found) {
        cout << "-1\n";
        return;
    }
    string result(count4, '4');
    result.append(count7, '7');
    cout << result << endl;
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
//SỐ MAY MẮN

