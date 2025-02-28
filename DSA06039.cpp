//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void Testcase() {
    int vecSize; cin >> vecSize;
    vector<int> nums(vecSize);
    bool found = false;
    unordered_map<int, int> umap;
    for(int i = 0; i < vecSize; i++) {
        cin >> nums[i];
        umap[nums[i]]++;
    }
    for(int i = 0; i < vecSize; i++) {
        if(umap[nums[i]] > 1) {
            cout << nums[i] << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//SỐ ĐẦU TIÊN BỊ LẶP