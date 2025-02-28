//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 07/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    int minVal = *min_element(numbers.begin(), numbers.end());
    int sum = 0;
    bool flag;
    int i;
    for (i = minVal; i > 0; i--) {
        flag = false;
        for (int j = 0; j < N; j++) {
            if (numbers[j] / i == numbers[j] / (i + 1)) {
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        }
        for (int j = 0; j < N; j++) {
            sum += (numbers[j] / (i + 1) + 1);
        }
        break;
    }
    cout << sum;
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//TÌM DÃY SỐ