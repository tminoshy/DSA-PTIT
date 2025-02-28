//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 20/09/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Testcase() {
    long long sz; cin >> sz;
    vector<long long> nums(sz);
    for (long long &i : nums) {
        cin >> i;
    }
    long long mod = 1e9 + 7;
    sort(nums.begin(), nums.end());
    long long sum = 0;
    for (long long i = 0; i < sz; i++) {
        sum += (nums[i] * i);
        sum %= mod;
    }
    cout << sum << endl;
}
int main() {
    long long testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
} 

//TÌM MAX