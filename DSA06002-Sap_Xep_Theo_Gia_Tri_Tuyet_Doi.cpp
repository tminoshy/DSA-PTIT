//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 14/08/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Testcase() {
    int n, X;
    cin >> n >> X;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (abs(numbers[j] - X) > abs(numbers[j + 1] - X)) {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }

    for (const int &value : numbers) {
        cout << value << " ";
    }
    cout << '\n';
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
//SẮP XẾP THEO GIÁ TRỊ TUYỆT ĐỐI