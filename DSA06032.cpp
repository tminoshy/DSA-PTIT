//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 17/09/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Testcase() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int &x : nums) {
        cin >> x;
    }
    sort(nums.begin(), nums.end());
    long long count = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            long long sum = nums[i] + nums[j];
            auto it = lower_bound(nums.begin() + j + 1, nums.end(), target - sum);
            count += distance(nums.begin() + j + 1, it);
        }
    }
    cout << count << endl;
}



int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//BỘ BA SỐ CÓ TỔNG NHỎ HƠN K