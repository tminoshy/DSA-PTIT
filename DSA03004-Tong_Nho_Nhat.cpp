//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 27/09/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int &value : numbers) {
        cin >> value;
    }
    sort(numbers.begin(), numbers.end());
    size_t index1 = 0, index2 = 1;
    long long number1 = 0, number2 = 0;
    while (index1 < numbers.size()) {
        number1 = number1 * 10 + numbers[index1];
        index1 += 2;
    }
    while (index2 < numbers.size()) {
        number2 = number2 * 10 + numbers[index2];
        index2 += 2;
    }
    cout << number1 + number2 << endl;
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
//TỔNG NHỎ NHẤT