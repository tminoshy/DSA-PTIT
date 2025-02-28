//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 23/08/2024

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Testcase() {
    int n; 
    cin >> n;
    vector<int> nums(n);

    for (int &element : nums) {
        cin >> element;
    }

    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());

    int front = 0;
    int back = n - 1;

    while (front < n - 1 && nums[front] == sorted[front]) {
        front++;
    }

    while (back > 0 && nums[back] == sorted[back]) {
        back--;
    }

    cout << front + 1 << " " << back + 1 << '\n';
    
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
//SẮP XẾP DÃY CON LIÊN TỤC 