//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void Testcase() {
    int size; cin >> size;
    vector<int> nums(size);
    for(int &i : nums) {
        cin >> i;
    }
    int cnt = 1;
    vector<vector<int>> Storage;
    for(int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for(int j = i + 1; j < size; j++) {
            if(nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
                swapped = true;
            }
        }
        if(swapped) {
                Storage.push_back(nums);
        }
    }
    for(int i = Storage.size() - 1; i >= 0; i--) {
        cout << "Buoc " << i + 1 << ": ";
        for(int j = 0; j < Storage[i].size(); j++) {
            cout << Storage[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//SẮP XẾP ĐỔI CHỖ TRỰC TIẾP - LIỆT KÊ NGƯỢC