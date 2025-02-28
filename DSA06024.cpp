//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void solve() {
    int size; cin >> size;
    vector<int> nums(size);
    for(int &x : nums) {
        cin >> x;
    }
    int count = 1;
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
        cout << "Buoc " << count++ << ": ";
        for(int element : nums) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}

//SẮP XẾP CHỌN