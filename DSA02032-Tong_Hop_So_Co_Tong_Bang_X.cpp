//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/09/2024

#include <iostream>
#include <vector>

using namespace std;

struct CombinationFinder {
    vector<int> source, currentCombination;
    vector<vector<int>> result;
    int combinationCount;

    CombinationFinder(int N) : source(N), combinationCount(0) {}
};

void findCombinations(CombinationFinder &a, int index, int currentSum, int targetSum) {
    if (index > a.source.size() || currentSum > targetSum) {
        return;
    }
    if (currentSum == targetSum) {
        a.result.push_back(a.currentCombination);
        a.combinationCount++;
        return;
    }
    for (size_t i = index; i < a.source.size(); i++) {
        a.currentCombination.push_back(a.source[i]);
        findCombinations(a, i, currentSum + a.source[i], targetSum);
        a.currentCombination.pop_back();
    }
}

void testcase() {
    int N, X;
    cin >> N >> X;
    CombinationFinder a(N); 
    for (size_t i = 0; i < N; i++) {
        cin >> a.source[i];
    }
    findCombinations(a, 0, 0, X);
    if (a.combinationCount == 0) {
        cout << "-1\n";
        return;
    }
    cout << a.combinationCount;
    for (const vector<int> &vec : a.result) {
        cout << " {";
        for (size_t i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i < vec.size() - 1) {
                cout << " ";
            }
        }
        cout << "}";
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