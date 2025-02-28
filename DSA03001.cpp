//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 19/09/2024

#include <iostream>
#include <vector>

using namespace std;

void Testcase() {
    int n; cin >> n;
    vector<int> money = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int count = 0;
    for (int i = 0; i < money.size(); i++) {
        count += n / money[i];
        n %= money[i];
    }
    cout << count << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//ĐỔI TIỀN