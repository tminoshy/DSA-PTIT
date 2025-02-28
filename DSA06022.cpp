//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Testcase() {
    int size; cin >> size;
    vector<int> nums(size);
    for(int &x : nums) {
        cin >> x;
    }
    sort(nums.begin(), nums.end());
    if(nums[0] < nums[1]) {
        cout << nums[0] << " " << nums[1];
    } else {
        cout << "-1";
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

//SỐ NHỎ NHẤT VÀ NHỎ THỨ HAI