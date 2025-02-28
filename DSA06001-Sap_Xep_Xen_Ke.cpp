//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 14/08/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Testcase() {
    int n; 
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int leftIndex = 0, rightIndex = n - 1;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {
            ans.push_back(numbers[leftIndex++]);
        } else {
            ans.push_back(numbers[rightIndex--]);
        }
    }

    for (const int& value : ans) {
        cout << value << " ";
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
//SẮP XẾP XEN KẼ