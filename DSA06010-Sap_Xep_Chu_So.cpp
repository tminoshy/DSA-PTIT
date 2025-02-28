//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 19/08/2024

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void Testcase() {
    int n; 
    cin >> n;
    vector<int> nums(n);
    unordered_set<int> uniqueDigits;
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        while(nums[i]) {
                int digit = nums[i] % 10;
                uniqueDigits.insert(digit);
                nums[i] /= 10;
        }
    }
    
    vector<int> digits(uniqueDigits.begin(), uniqueDigits.end());
    sort(digits.begin(), digits.end());
    
    for (const int& digit : digits) {
        cout << digit << " ";
    }
    cout << '\n';
}

int main() {
    int testCount; 
    cin >> testCount;

    while (testCount--) {
        Testcase();
    }
    
    return 0;
}

//B23DCCE064
//SẮP XẾP CHỮ SỐ