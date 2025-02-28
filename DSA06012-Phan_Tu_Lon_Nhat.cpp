//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 19/08/2024

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Testcase() {
    int N, K;
    cin >> N >> K;
    vector<int> nums(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    for (int i = N - 1; i >= N - K; i--) {
        cout << nums[i] << " ";
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
//PHẦN TỬ LỚN NHẤT