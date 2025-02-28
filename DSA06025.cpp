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
    vector<int> sorted;
    sorted.insert(sorted.begin(), nums[0]);
    cout << "Buoc 0: " << sorted[0] << endl;
    int count = 1;
    for(int i = 1; i < size; i++) {
        bool inserted = false;
        for(int j = sorted.size() - 1; j >= 0; j--) {
            if(sorted[j] < nums[i]) {
                sorted.insert(sorted.begin() + j + 1, nums[i]);
                inserted = true;
                break;
            }
        }
        if(!inserted) {
            sorted.insert(sorted.begin() + 0, nums[i]);
        }
        cout << "Buoc " << count++ << ": ";
        for(int value : sorted) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}

//SẮP XẾP CHÈN