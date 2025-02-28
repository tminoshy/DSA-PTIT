//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

void testcase() {
    int K; cin >> K;
    string S; cin >> S;
    unordered_map<char, int> umap;
    for (const char& c : S) {
        umap[c]++;
    }
    vector<int> freq;
    for (const auto& p : umap) {
        freq.push_back(p.second);
    }
    while (K--) {
        auto max_it = max_element(freq.begin(), freq.end());
        (*max_it)--;
    }
    int sum = 0;
    for (const int& value : freq) {
        sum += value * value;
    }
    cout << sum << endl;
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
//GIÁ TRỊ NHỎ NHẤT CỦA XÂU