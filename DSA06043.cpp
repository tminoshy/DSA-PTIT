//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>

using namespace std;

void Testcase() {
    int vecS; cin >> vecS;
    vector<int> nums(vecS);
    int vecSum = 0;
    for(int &i : nums) {
        cin >> i;
        vecSum += i;
    }
    int leftSum = 0;
    int rightSum = vecSum;
    for(int i = 0; i < vecS; i++) {
        rightSum -= nums[i];
        leftSum = vecSum - rightSum - nums[i];
        if(leftSum == rightSum) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << "-1" << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//ĐIỂM CÂN BẰNG