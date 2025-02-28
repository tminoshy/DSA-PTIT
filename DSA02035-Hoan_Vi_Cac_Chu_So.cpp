//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/09/2024

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int calculate(const vector<string>& numbers, const vector<int>& permutation) {
    vector<string> permutedNumbers(numbers.size());
    for (size_t i = 0; i < numbers.size(); i++) {
        for (size_t j = 0; j < permutation.size(); j++) {
            permutedNumbers[i] += numbers[i][permutation[j]];
        }
    }
    sort(permutedNumbers.begin(), permutedNumbers.end());
    return stoi(permutedNumbers.back()) - stoi(permutedNumbers.front());
}


void findMinSubstract(int depth, vector<int> &permutation, vector<bool> &visited, const vector<string>& numbers, int &minDifference) {
    if (depth == permutation.size()) {
        minDifference = min(minDifference, calculate(numbers, permutation));
        return;
    }
    for (int i = 0; i < numbers[0].size(); i++) {
        if (visited[i] == false) {
            visited[i] = true;
            permutation[depth] = i;
            findMinSubstract(depth + 1, permutation, visited, numbers, minDifference);
            visited[i] = false;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> numbers(n);
    for (string &s : numbers) {
        cin >> s;
    }
    vector<int> permutation(k);
    vector<bool> visited(k, false);
    int currentSubstract = INT_MAX;
    findMinSubstract(0, permutation, visited, numbers, currentSubstract);
    cout << currentSubstract;
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//HOÁN VỊ CÁC CHỮ SỐ 