//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void generateSubset(int index, int k, int currentSum, int targetSum, vector<int>& currentSubset, const vector<int>& numbers, int& count) {
    if (currentSum > targetSum) {
        return;
    }
    if (currentSubset.size() == k) {
        if (currentSum == targetSum) {
            count++;
        }
        return;
    }
    if (index >= numbers.size()) {
        return;
    }
    currentSubset.push_back(numbers[index]);
    generateSubset(index + 1, k, currentSum + numbers[index], targetSum, currentSubset, numbers, count);
    currentSubset.pop_back();
    generateSubset(index + 1, k, currentSum, targetSum, currentSubset, numbers, count);
}

void solve() {
    int n, k, s;
    while (cin >> n >> k >> s) {
        if (n == 0 && k == 0 && s == 0) {
            break;
        }
        vector<int> numbers(n);
        iota(numbers.begin(), numbers.end(), 1);
        vector<int> currentSubset;
        int count = 0;
        generateSubset(0, k, 0, s, currentSubset, numbers, count);
        cout << count << endl;
    }
}
    

int main() {
    solve();
    return 0;
}

//B23DCCE064
//TẬP HỢP