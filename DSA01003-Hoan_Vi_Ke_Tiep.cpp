//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 17/09/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Testcase() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int &value : numbers) {
        cin >> value;
    }
    int i = numbers.size() - 2;
    while (i >= 0 && numbers[i] > numbers[i + 1]) {
        i--;
    }
    if (i < 0) {
        reverse(numbers.begin(), numbers.end());
    } else {
        int j = numbers.size() - 1;
        while (j > i && numbers[j] < numbers[i]) {
            j--;
        }
        swap(numbers[i], numbers[j]);
        reverse(numbers.begin() + i + 1, numbers.end());
    }
    for (const int &value : numbers) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//B23DCCE064
//HOÁN VỊ KẾ TIẾP