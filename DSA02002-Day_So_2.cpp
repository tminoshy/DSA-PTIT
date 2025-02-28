//https://github.com/tminoshy
//created by Đỗ Thiện Minh at 17/09/2024

#include <iostream>
#include <vector>

using namespace std;

void generateNextLevel(const vector<int>& numbers) {
    if (numbers.empty()) {
        return;
    }
    vector<int> nextLevel(numbers.size() - 1);
    for (size_t i = 0; i < numbers.size() - 1; i++) {
        nextLevel[i] = numbers[i] + numbers[i + 1];
    }
    generateNextLevel(nextLevel);
    cout << "[";
    for (size_t i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
        if (i < numbers.size() - 1) {
            cout << " ";
        }
    }
    cout << "]" << " ";
}

void testcase() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int &value : numbers) {
        cin >> value;
    }
    generateNextLevel(numbers);
    cout << endl;
}

int main() {
    int testCaseCount; cin >> testCaseCount;
    while (testCaseCount--) {
        testcase();
    }
    return 0;
}

//B23DCCE064
//DÃY SỐ 2