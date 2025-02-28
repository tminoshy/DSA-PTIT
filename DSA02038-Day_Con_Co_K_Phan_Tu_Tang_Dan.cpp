//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/09/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateSubset(int index, int K, vector<int>& currentSubset, const vector<int>& numbers) {
    if (index > numbers.size()) {
        return;
    }
    if (currentSubset.size() == K) {
        for (const int& value : currentSubset) {
            cout << value << " ";
        }
        cout << endl;
        return;
    }
    
    currentSubset.push_back(numbers[index]);
    generateSubset(index + 1, K, currentSubset, numbers);
    currentSubset.pop_back();
    generateSubset(index + 1, K, currentSubset, numbers);
}

void testcase() {
    int N, K;
    cin >> N >> K;
    vector<int> numbers(N);
    for (int &value : numbers) {
        cin >> value;
    }
    sort(numbers.begin(), numbers.end());
    vector<int> currentSubset;
    generateSubset(0, K, currentSubset, numbers);
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
//DÃY CON CÓ K PHẦN TỬ TĂNG DẦN