//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 07/09/2024

#include <iostream>
#include <vector>

using namespace std;

void generateCombinations(const vector<int> &numbers, vector<int> &currentCombination, int total, int index) {
    if(currentCombination.size() == total) {
        for (const int &value : currentCombination) {
            cout << value;
        }
        cout << " ";
        return;
    }
    if(index == numbers.size()) {
        return;
    }
    
    currentCombination.push_back(numbers[index]);
    generateCombinations(numbers, currentCombination, total, index + 1);
    currentCombination.pop_back();
    generateCombinations(numbers, currentCombination, total, index + 1);
}

void Testcase() {
    int N, K;
    cin >> N >> K;
    vector<int> currentCombination;
    vector<int> numbers(N);
    for (size_t i = 0; i < N; i++) {
        numbers[i] = i + 1;
    }
    generateCombinations(numbers, currentCombination, K, 0);
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
//SINH TỔ HỢP