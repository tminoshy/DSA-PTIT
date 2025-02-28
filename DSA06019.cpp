//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool compares(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
} 

void Testcase() {
    int n; cin >> n;
    unordered_map<int, int> umap;
    vector<int> myVec(n);
    for(int i = 0; i < n; i++) {
        cin >> myVec[i];
        umap[myVec[i]]++;
    }
    vector<pair<int, int>> storage;
    for(auto x : umap) {
        storage.push_back(x);
    }
    sort(storage.begin(), storage.end(), compares);
    for(auto x : storage) {
        for(int i = 0; i < x.second; i++) {
            cout << x.first << " ";
        }
    }
    cout << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//SẮP XẾP THEO SỐ LẦN XUẤT HIỆN