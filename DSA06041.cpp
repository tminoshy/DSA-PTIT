//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void Testcase() {
    int vecS; cin >> vecS;
    vector<pair<int, int>> myVec;
    unordered_map<int, int> umap;
    for(int i = 0; i < vecS; i++) {
        int element; cin >> element;
        umap[element]++;
    }
    for(auto x : umap) {
        myVec.push_back(x);
    }
    sort(myVec.begin(), myVec.end(), cmp);
    int val = myVec[myVec.size() - 1].first;
    int repeat = myVec[myVec.size() - 1].second;
    if(repeat > vecS / 2) {
        cout << val << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//SỐ XUẤT HIỆN NHIỀU NHẤT