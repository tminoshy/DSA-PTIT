//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 04/10/2024

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void testcase() {
    int N, K;
    cin >> N >> K;
    vector<int> numbers(K);
    unordered_set<int> uset;
    for (int& value : numbers) {
        cin >> value;
        uset.insert(value);
    }
    int index = K - 1;
    while (numbers[index] == N - K + index + 1) {
        index--;
    }
    if (index < 0) {
        cout << K << endl;
        return;
    }
    numbers[index]++;
    for (int j = index + 1; j < K; j++) {
        numbers[j] = numbers[index] + j - index;
    }
    int count = 0;
    for (int i = 0; i < K; i++) {
        if (uset.insert(numbers[i]).second == false) {
            count++;
        }
    }
    cout << K - count << endl;

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
//TẬP QUÂN SỰ