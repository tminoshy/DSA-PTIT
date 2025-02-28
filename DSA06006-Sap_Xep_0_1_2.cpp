//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/08/2024

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Testcase() {
    int n; 
    cin >> n;
    vector<int> numbers(n);
    for (int &value : numbers) {
        cin >> value;
    }

    sort(numbers.begin(), numbers.end());

    for (const int &value : numbers) {
        cout << value << " ";
    }
    cout << '\n';
}

int main() {
    int testCount; cin >> testCount;
    while (testCount--) {
        Testcase();
    }
    return 0;
}

//B23DCCE064
//SẮP XẾP [0 1 2]