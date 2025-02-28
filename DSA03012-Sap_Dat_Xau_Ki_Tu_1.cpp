//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/09/2024

#include <iostream>
#include <unordered_map>

using namespace std;

void testcase() {
    string S; cin >> S;
    unordered_map<char, int> umap;
    for (const char& c : S) {
        umap[c]++;
    }
    for (auto it : umap) {
        if (it.second * 2 - 1 > S.size()) {
            cout << "-1\n";
            return;
        }
    }
    cout << "1\n";
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
//SẮP ĐẶT XÂU KÝ TỰ 1