//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 27/09/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int N, K;
    cin >> N >> K;
    vector<int> numbers(N);
    for (int &value : numbers) {
        cin >> value;
    }
    int left = 0, right = numbers.size() - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (numbers[middle] == K) {
            cout << middle + 1 << endl;
            return;
        } else if (numbers[middle] > K) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    cout << "NO\n";
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
//TÌM KIẾM NHỊ PHÂN