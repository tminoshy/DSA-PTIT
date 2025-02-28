//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int size; cin >> size;
    vector<int> nums(size);
    for(int &x : nums) {
        cin >> x;
    }
    vector<vector<int>> storage;
    for(int i = 0; i < size - 1; i++) {
        int smallestIndex = i;
        bool found = false;
        for(int j = i + 1; j < size; j++) {
            if(nums[j] < nums[smallestIndex]) {
                smallestIndex = j;
                found = true;
            }
        }
        if(found) {
            swap(nums[i], nums[smallestIndex]);
        }
        storage.push_back(nums);
    }
    for(int i = storage.size() - 1; i >= 0; i--) {
        cout << "Buoc " << i + 1 << ": ";
        for(int j = 0; j < storage[i].size(); j++) {
            cout << storage[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    solve();
    return 0;
}

//SẮP XẾP CHỌN - LIỆT KÊ NGƯỢC