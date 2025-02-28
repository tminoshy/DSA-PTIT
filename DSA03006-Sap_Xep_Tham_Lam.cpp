//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/09/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int &value : numbers) {
        cin >> value;
    }
    for (size_t i = 0; i < N; i++) {
        if (numbers[i] != i + 1 && numbers[i] != N - i) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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
//SẮP XẾP THAM LAM