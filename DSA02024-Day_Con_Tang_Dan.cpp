//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 24/09/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateSequences(int index, vector<int>& currentSequence, const vector<int>& numbers, vector<vector<int>>& result) {
    if (currentSequence.size() >= 2) {
        result.push_back(currentSequence);
    }
    for (int i = index; i < numbers.size(); ++i) {
        if (currentSequence.empty() || numbers[i] > currentSequence.back()) {
            currentSequence.push_back(numbers[i]);
            generateSequences(i + 1, currentSequence, numbers, result);
            currentSequence.pop_back();
        }       
    }
}

bool lexicographicalCompare(const vector<int>& a, const vector<int>& b) {
    string A = "", B = "";
    for (const int &element : a) {
        A += (to_string(element) + " "); 
    }
    for (const int &element : b) {
        B += (to_string(element) + " ");
    }
    return A < B;
}

void solve() {
    int n; cin >> n;
    vector<int> numbers(n);
    for (int& element : numbers) {
        cin >> element;
    }
    vector<int> currentSequence;
    vector<vector<int>> result;
    generateSequences(0, currentSequence, numbers, result);
    sort(result.begin(), result.end(), lexicographicalCompare);
    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//DÃY CON TĂNG DẦN