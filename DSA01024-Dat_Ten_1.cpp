//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 17/09/2024

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

void generateCombinations(int index, int K, vector<string>& currentCombination,  const vector<string> &uniqueWords) {
    if (currentCombination.size() == K) {
        for (const string &s : currentCombination) {
            cout << s << " ";
        }
        cout << endl;
        return;
    }
    if (index == uniqueWords.size()) {
        return;
    }
    currentCombination.push_back(uniqueWords[index]);
    generateCombinations(index + 1, K, currentCombination, uniqueWords);
    currentCombination.pop_back();
    generateCombinations(index + 1, K, currentCombination, uniqueWords);
}

void solve() {
    int N, K;
    cin >> N >> K;
    unordered_set<string> uset;
    for (size_t i = 0; i < N; i++) {
        string word; cin >> word;
        uset.insert(word);
    }
    vector<string> uniqueWords(uset.begin(), uset.end());
    sort(uniqueWords.begin(), uniqueWords.end());
    vector<string> currentCombination;
    generateCombinations(0, K, currentCombination, uniqueWords);
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//ĐẶT TÊN - 1