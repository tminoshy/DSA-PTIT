//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 19/08/2024

#include <iostream>
#include <vector>

using namespace std;

void Testcase() {
    int N, target; 
    cin >> N >> target;
    vector<int> nums(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int count = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (nums[i] + nums[j] == target) {
                count++;
            }
        }
    }
    
    cout << count << '\n';
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
//CẶP SỐ TỔNG BẰNG K