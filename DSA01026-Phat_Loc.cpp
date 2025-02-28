//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 16/09/2024

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> storage;

bool isValid(const string &currentCombination) {
    if(currentCombination.front() != '8' || currentCombination.back() != '6' || currentCombination.find("88") != -1 || currentCombination.find("6666") != -1) {
        return false;
    }
    return true;
}

void generateCombinations(int index, int sz, const string currentCombination) {
    if (index == sz) {
        if (isValid(currentCombination)) {
            storage.push_back(currentCombination);
        }
        return;
    }
    generateCombinations(index + 1, sz, currentCombination + '6');
    generateCombinations(index + 1, sz, currentCombination + '8');

}

void solve() {
    int n; cin >> n;
    string currentCombination;
    generateCombinations(0, n, currentCombination);
    for (string s : storage) {
        cout << s << endl;
    }

}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//PHÁT LỘC