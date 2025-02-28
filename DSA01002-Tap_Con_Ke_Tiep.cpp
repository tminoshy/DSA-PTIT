//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 16/09/2024

#include <iostream>
#include <vector>

using namespace std;

void Testcase() {
    int N, K;
    cin >> N >> K;
    vector<int> nums(K);
    for (int &value : nums) {
        cin >> value;
    }
    int i = K - 1;
    while (i >= 0 && nums[i] == N - K + i + 1) {
        i--;
    }
    if (i >= 0) {
        nums[i]++;
        for (size_t j = i + 1; j < K; j ++) {
            nums[j] = nums[i] + j - i;
        }
    } else {
        for (size_t l = 1; l <= K; l++) {
            nums[l - 1] = l;
        }
    }
    for (const int &x : nums) {
        cout << x << " ";
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

//B23DCCE064
//TẬP CON KẾ TIẾP
