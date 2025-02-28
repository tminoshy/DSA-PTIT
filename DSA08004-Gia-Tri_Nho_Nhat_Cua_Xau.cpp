//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

void testcase() {
    int K; cin >> K;
    string S; cin >> S;
    // Count the frequency of each character in the string
    unordered_map<char, int> charFrequency;
    for (const char& c : S) {
        charFrequency[c]++;
    }
    // Create a max-heap priority queue to store the frequencies
    priority_queue<int> maxHeap;
    for (const auto& entry : charFrequency) {
        maxHeap.push(entry.second);
    }
    // Reduce the highest frequency K times
    long long minVal = 0;
    while (K-- && !maxHeap.empty()) {
        int topFreq = maxHeap.top();
        maxHeap.pop();
        if (topFreq > 1) {
            maxHeap.push(topFreq - 1);
        }
    }
    // Calculate the sum of squares of the remaining frequencies
    while (!maxHeap.empty()) {
        minVal += static_cast<long long>(maxHeap.top()) * maxHeap.top();
        maxHeap.pop();
    }
    cout << minVal << '\n';
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
//GIÁ TRỊ NHỎ NHẤT CỦA XÂU