//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 18/09/2024

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

void generateCombination(int index, int K, vector<string>& currentCombination, const vector<string>& uniqueNames) {
    if (currentCombination.size() == K) {
        for (const string& name : currentCombination) {
            cout << name << " ";
        }
        cout << endl;
        return;
    }
    if (index == uniqueNames.size()) {
        return;
    }
    currentCombination.push_back(uniqueNames[index]);
    generateCombination(index + 1, K, currentCombination, uniqueNames);
    currentCombination.pop_back();
    generateCombination(index + 1, K, currentCombination, uniqueNames);
}

void solve() {
    int N, K;
    cin >> N >> K;
    unordered_set<string> uniqueNamesSet;
    for (size_t i = 0; i < N; i++) {
        string name; cin >> name;
        uniqueNamesSet.insert(name);
    }
    vector<string> uniqueNames(uniqueNamesSet.begin(), uniqueNamesSet.end());
    sort(uniqueNames.begin(), uniqueNames.end());
    vector<string> currentCombination;
    generateCombination(0, K, currentCombination, uniqueNames);
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//ĐẶT TÊN