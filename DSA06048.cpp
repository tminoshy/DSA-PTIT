//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void Testcase() {
    long long vecS; cin >> vecS;
    vector<long long> nums(vecS);
    for(long long &i : nums) {
        cin >> i;
    }
    long long smallest = nums[0];
    for(long long value : nums) {
        if(value < smallest) {
            smallest = value;
        }
    }
    long long indx;
    for(long long i = 0; i < vecS; i++) {
        if(nums[i] == smallest) {
            indx = i;
        }
    }
    cout << indx << endl;
}

int main() {
    long long testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//SỐ LẦN QUAY VÒNG