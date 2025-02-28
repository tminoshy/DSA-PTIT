//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/09/2024

#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

void testcase() {
    int D; cin >> D;
    string S; cin >> S;
    unordered_map<char, int> umap;
    int max = 0;
    for (const char& c : S) {
        umap[c]++;
        max = (umap[c] > max) ? umap[c] : max;
    }
    if (max <= ceil(static_cast<double>(S.size()) / D)) {
        cout << "1\n";
    } else {
        cout << "-1\n";
    }
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
//SẮP ĐẶT XÂU KÝ TỰ 2