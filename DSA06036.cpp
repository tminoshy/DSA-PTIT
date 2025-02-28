//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 17/09/2024

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Testcase() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int &i : nums) {
        cin >> i;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                cout << "YES" << endl;
                return;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
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

//BỘ BA SỐ BẰNG K