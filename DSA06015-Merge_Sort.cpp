//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 19/08/2024

#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int> &nums, int left, int middle, int right) {
    int leftIndex = left, rightIndex = middle + 1;
    vector<int> merged;

    // Combine two sorted vectors
    while (leftIndex <= middle && rightIndex <= right) {
        if (nums[leftIndex] <= nums[rightIndex]) {
            merged.push_back(nums[leftIndex++]);
        } else {
            merged.push_back(nums[rightIndex++]);
        }
    }

    // Copy remaining elements of left half, if any
    while (leftIndex <= middle) {
        merged.push_back(nums[leftIndex++]);
    }

    // Copy remaining elements of right half, if any
    while (rightIndex <= right) {
        merged.push_back(nums[rightIndex++]);
    }
    
    for (int i = 0; i < merged.size(); i++) {
        nums[left + i] = merged[i];
    }
}

void MergeSort(vector<int> &nums, int head, int back) {
    // Base case : have only 1 element
    if (head >= back) {
        return;
    }

    int middle = head + (back - head) / 2;

    MergeSort(nums, head, middle); // Sort the first half
    MergeSort(nums, middle + 1, back); // Sort the second half

    Merge(nums, head, middle, back); // Merge the sorted halves
}

void Testcase() {
    int size;
    cin >> size;    
    vector<int> nums(size);

    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    MergeSort(nums, 0, size - 1);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
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
//MERGE SORT