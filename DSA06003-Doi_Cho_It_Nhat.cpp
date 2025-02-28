//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 9/6/2024

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void Testcase() {
    int n; 
    cin >> n;
    vector<int> numbers(n);

    for (int &value : numbers) {
        cin >> value;
    }

    int swapCount = 0;

    for (size_t i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (numbers[minIndex] > numbers[j]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(numbers[minIndex], numbers[i]);
            swapCount++;
        }
    }

    cout << swapCount << '\n';
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
//ĐỔI CHỖ ÍT NHẤT