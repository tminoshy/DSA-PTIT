//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 18/09/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findSubset(int index, int currentSum, const vector<int>& numbers, vector<int>& currentSubset, int targetSum, bool& found) {
    if (currentSum == targetSum) {
        found = true;
        cout << "[";
        for (size_t i = 0; i < currentSubset.size(); i++) {
            cout << currentSubset[i];
            if (i < currentSubset.size() - 1) {
                cout << " ";
            }
        }
        cout << "] ";
        return;
    }
    if (index == numbers.size() || currentSum > targetSum) {
        return;
    }
    currentSubset.push_back(numbers[index]);
    findSubset(index + 1, currentSum + numbers[index], numbers, currentSubset, targetSum, found);
    currentSubset.pop_back();
    findSubset(index + 1, currentSum, numbers, currentSubset, targetSum, found);
}

void testcase() {
    int N, K;
    cin >> N >> K;
    vector<int> numbers(N);
    for (int &element : numbers) {
        cin >> element;
    }
    bool found = false;
    sort(numbers.begin(), numbers.end());
    vector<int> currentSubset;
    findSubset(0, 0, numbers, currentSubset, K, found);
    if (!found) {
        cout << "-1";
    }
    cout << endl;
}

int main() {
    int testCaseCount; cin >> testCaseCount;
    while(testCaseCount--) {
        testcase();
    }
    return 0;
}

//B23DCCE064
//DÃY CON TỔNG BẰNG K