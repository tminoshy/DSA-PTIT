//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 04/10/2024

#include <iostream>
#include <vector>

using namespace std;

void generateIncreasingSubset(int index, int K, vector<int>& currentSubset, const vector<int>& numbers, int& count) {
    if (index > numbers.size()) {
        return;
    }
    if (currentSubset.size() == K) {
        count++;
        return;
    }
    if (currentSubset.size() == 0 || currentSubset.back() < numbers[index]) {
        currentSubset.push_back(numbers[index]);
        generateIncreasingSubset(index + 1, K, currentSubset, numbers, count);
        currentSubset.pop_back();
    }
    generateIncreasingSubset(index + 1, K, currentSubset, numbers, count);
}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    vector<int> currentSubset;
    int count = 0;
    generateIncreasingSubset(0, K, currentSubset, numbers, count);
    cout << count;
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//DÃY CON TĂNG DẦN BẬC K