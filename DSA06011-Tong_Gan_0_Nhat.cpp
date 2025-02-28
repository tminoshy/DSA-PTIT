//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 19/08/2024

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void Testcase() {
    int N; 
    cin >> N;
    vector<int> nums(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int nearZero = INT_MAX;
    int near = 0;
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int sum = nums[i] + nums[j];
            if (abs(sum) < nearZero) {
                nearZero = abs(sum);
                near = sum;
            }
        }
    }

    cout << near << '\n';
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
//TỔNG GẦN 0 NHẤT