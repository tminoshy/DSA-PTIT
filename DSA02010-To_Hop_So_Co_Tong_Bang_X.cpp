//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 26/09/2024

#include <iostream>
#include <vector>

using namespace std;

void generateCombinations(int index, int currentSum, int targetSum, const vector<int> &number, vector<int> &currentCombination, bool &found) {
    if (index == number.size() || currentSum > targetSum) {
        return;
    }
    if (currentSum == targetSum) {
        found = true;
        cout << "[";
        for (size_t i = 0; i < currentCombination.size(); i++) {
            cout << currentCombination[i];
            if (i < currentCombination.size() - 1) {
                cout << " ";
            }
        }
        cout << "]";
        return;
    }
    for (size_t i = index; i < number.size(); i++) {
        currentCombination.push_back(number[i]);
        generateCombinations(i, currentSum + number[i], targetSum, number, currentCombination, found);
        currentCombination.pop_back();
    }
}

void testcase() {
    int N, X;
    cin >> N >> X;
    vector<int> number(N);
    for (int &value : number) {
        cin >> value;
    }
    vector<int> currentCombination;
    bool found = false;
    generateCombinations(0, 0, X, number, currentCombination, found);
    if(!found) {
        cout << "-1";
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
//TỔ HỢP SỐ CÓ TỔNG BẰNG X