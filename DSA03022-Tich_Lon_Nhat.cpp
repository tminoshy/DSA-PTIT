//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/09/2024

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
    sort(numbers.begin(), numbers.end());
    vector<int> result; 
    result.push_back(numbers[0] * numbers[1]);
    result.push_back(numbers[0] * numbers[1] * numbers[N - 1]);
    result.push_back(numbers[N - 3] * numbers[N - 2] * numbers[N - 1]);
    result.push_back(numbers[N - 2] * numbers[N - 1]);
    sort(result.rbegin(), result.rend());
    cout << result[0];
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//TÍCH LỚN NHẤT