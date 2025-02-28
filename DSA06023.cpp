//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void solve() {
    int size; cin >> size;
    vector<int> nums(size);
    for(int &i : nums) {
        cin >> i;
    }
    int cnt = 1;
    for(int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for(int j = i + 1; j < size; j++) {
            if(nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
                swapped = true;
            }
        }
        if(swapped) {
                cout << "Buoc " << cnt << ": ";
                for(int i : nums) {
                    cout << i << " ";
                }
                cout << endl;
                cnt++;
            }
    }
}

int main() {
    solve();
    return 0;
}

//SẮP XẾP ĐỔI CHỖ TRỰC TIẾP 