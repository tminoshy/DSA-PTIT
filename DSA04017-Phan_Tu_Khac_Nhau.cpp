//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/9/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int N; cin >> N;
    vector<long long> A(N), B(N - 1);
    for (long long &value : A) {
        cin >> value;
    }
    int ans = -1;
    for (size_t i = 0; i < N - 1; i++) {
        int value; cin >> value;
        if (ans == -1 && A[i] != value) {
            ans = i + 1;
        }
    }
    cout << ans << endl;
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
//PHẦN TỬ KHÁC NHAU