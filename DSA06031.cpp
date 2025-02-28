//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void Testcase() {
    int N, K;
    cin >> N >> K;
    vector<int> nums(N);
    for(int &i : nums) {
        cin >> i;
    }
    vector<int> maxofrangeK;
    for(int i = 0; i < N - K + 1; i++) {
        int max = nums[i];
        for(int j = i + 1; j < i + K; j++) {
            if(max < nums[j]) {
                max = nums[j];
            }
        }
        maxofrangeK.push_back(max);
    }
    for(int value : maxofrangeK) {
        cout << value << " ";
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

//PHẦN TỬ LỚN NHẤT TRONG DÃY CON