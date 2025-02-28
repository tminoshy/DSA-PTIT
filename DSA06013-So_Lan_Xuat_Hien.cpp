//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 19/08/2024

#include <iostream>
#include <vector>

using namespace std;

void Testcase() {
    int size;
    cin >> size;
    int target; 
    cin >> target;
    vector<int> nums(size);

    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    int count = 0;
    int found = false;

    for (int i = 0; i < size; i++) {
        if (nums[i] == target) {
            count++;
            found = true;
        }
    }
    if (found) {
        cout << count << "\n";
    } else {
        cout << "-1\n";
    }
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
//SỐ LẦN XUẤT HIỆN