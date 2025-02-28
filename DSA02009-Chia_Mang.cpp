//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 08/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPartition(int index, int targetSum, vector<int>& subsetSum, const vector<int>& numbers) {
    // Base case: if we have considered all elements
    if (index == numbers.size()) {
        for (const int& value : subsetSum) {
            if (value != targetSum) {
                return false;
            }
        }
        return true;
    }
    // Try to place the current element in each subset
    for (int i = 0; i < subsetSum.size(); i++) {
        // If adding the current element to the subset does not exceed the target sum
        if (subsetSum[i] + numbers[index] <= targetSum) {
            subsetSum[i] += numbers[index]; // Add the element to the subset
            if (canPartition(index + 1, targetSum, subsetSum, numbers)) {
                return true;
            }
            subsetSum[i] -= numbers[index]; // Backtrack
        }
        // If the current subset is empty, break to avoid redundant work
        if (subsetSum[i] == 0) {
            break;
        }
    }
    return false;
}

void testcase() {
    int N, K;
    cin >> N >> K;
    int totalSum = 0;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
        totalSum += value;
    }
    // If the total sum is not divisible by K, partitioning is not possible
    if (totalSum % K != 0) {
        cout << "0\n";
        return;
    }
    int targetSum = totalSum / K;
    sort(numbers.rbegin(), numbers.rend()); // Sort the numbers in descending order for optimization
    vector<int> subsetSum(K);
    if (canPartition(0, targetSum, subsetSum, numbers)) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
}

int main() {
    int testCaseCount;
    cin >> testCaseCount;
    while (testCaseCount--) {
        testcase();
    }
    return 0;
}

//B23DCCE064
//CHIA MẢNG