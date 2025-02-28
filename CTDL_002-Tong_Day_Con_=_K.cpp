//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 02/09/2024

#include <iostream>
#include <vector>

using namespace std;

void findSubset(const vector<int>& numbers, vector<int>& subset, int index, int currentSum, int targetSum, int& subsetCount) {
    if (currentSum == targetSum) {
        for (size_t i = 0; i < subset.size(); i++) {
            cout << subset[i] << " ";
        }
        cout << endl;
        subsetCount++;
        return;
    }
    if (index >= numbers.size() || currentSum > targetSum) return;

    findSubset(numbers, subset, index + 1, currentSum, targetSum, subsetCount);

    subset.push_back(numbers[index]);
    findSubset(numbers, subset, index + 1, currentSum + numbers[index], targetSum, subsetCount);
    subset.pop_back();
}

void solve() {
    int N, K; 
    cin >> N >> K;
    vector<int> numbers(N);
    for (size_t i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    int subsetCount = 0;
    vector<int> subset;
    findSubset(numbers, subset, 0, 0, K, subsetCount);
    cout << subsetCount << endl;
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//Tổng dãy con = K