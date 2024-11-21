#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the length of the longest increasing subsequence in pairs
int longest_increasing_subsequence_length(vector<pair<int, int>>& pairs) {
    // Sort pairs by first element, and by second element if first elements are equal

    // Extract the second elements
    vector<int> second_elements;
    for (const auto& pair : pairs) {
        second_elements.push_back(pair.second);
    }

    // Find the LIS using binary search
    vector<int> lis;
    for (int elem : second_elements) {
        auto pos = lower_bound(lis.begin(), lis.end(), elem);
        if (pos == lis.end()) {
            lis.push_back(elem);
        }
    }

    return lis.size();
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    // Get the length of the longest increasing subsequence
    int result = longest_increasing_subsequence_length(pairs);

    // Print the result
    cout << result << endl;

    return 0;
}