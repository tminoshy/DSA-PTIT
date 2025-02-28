//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Testcase() {
    int sz; cin >> sz;
    int target; cin >> target;
    vector<int> nums(sz);
    for(int &x : nums) {
        cin >> x;
    }
    sort(nums.begin(), nums.end());
    int j = 0;
    long long ans = 0;
    for(int i = 0; i < sz; i++) {
        auto pos = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + target);
        ans += distance(nums.begin() + i + 1, pos);
    }
    cout << ans << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//ĐẾM CẶP