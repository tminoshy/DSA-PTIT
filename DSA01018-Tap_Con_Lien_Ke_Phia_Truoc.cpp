//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 07/10/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int N, K;
    cin >> N >> K;
    vector<int> numbers(K + 1, 0);
    for (int i = 1; i <= K; i++) {
        cin >> numbers[i];
    }
    int index = K;
    // Find the index where the (current + 1) element is bigger than the previous by 1
    while (index > 0 && numbers[index] == numbers[index - 1] + 1) {
        index--;
    }
    // If such an element is found, decrement it
    if (index != 0) {
        numbers[index]--;
    }
    // Adjust the elements to the right of the decremented element
    for (int i = index + 1; i <= K; i++) {
        numbers[i] = N - K + i;
    }
    for (int i = 1; i <= K; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
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
//TẬP CON LIỀN KỀ PHÍA TRƯỚC