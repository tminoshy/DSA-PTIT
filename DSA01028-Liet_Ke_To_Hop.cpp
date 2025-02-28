//https://github.com/tminoshy
//created by Đỗ Thiện Minh at 16/09/2024

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

void generateCombinations(int index, int K, vector<int>& currentCombination, const vector<int>& unique) {
    if (currentCombination.size() == K) {
        for (const int &value : currentCombination) {
            cout << value << " ";
        }
        cout << endl;
        return;
    }
    if (index >= unique.size()) {
        return;
    }
    currentCombination.push_back(unique[index]);
    generateCombinations(index + 1, K, currentCombination, unique);
    currentCombination.pop_back();
    generateCombinations(index + 1, K, currentCombination, unique);
}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> unique;
    unordered_set<int> uniqueSet;
    for (size_t i = 0; i < N; i++) {
        int element; cin >> element;
        if (uniqueSet.insert(element).second) {
            unique.push_back(element);
        }
    }
    sort(unique.begin(), unique.end());
    vector<int> currentCombination;
    generateCombinations(0, K, currentCombination, unique);
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//LIỆT KÊ TỔ HỢP