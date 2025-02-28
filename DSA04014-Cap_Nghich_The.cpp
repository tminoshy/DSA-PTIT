//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 09/10/2024

#include <iostream>
#include <vector>

using namespace std;

long long merge_and_count(int left, int middle, int right, vector<int> &numbers) {
    int i = left, j = middle + 1;
    long long inv_count = 0;
    vector<int> temp;

    while (i <= middle && j <= right) {
        if (numbers[i] <= numbers[j]) {
            temp.push_back(numbers[i++]);
        } else {
            inv_count += (middle - i + 1);
            temp.push_back(numbers[j++]);
        }
    }

    while (i <= middle) {
        temp.push_back(numbers[i++]);
    }

    while (j <= right) {
        temp.push_back(numbers[j++]);
    }

    copy(temp.begin(), temp.end(), numbers.begin() + left);

    return inv_count;
}

long long mergeSort_and_count(int left, int right, vector<int> &numbers) {
    long long inv_count = 0;
    if (left < right) {
        int middle = left + (right - left) / 2;
        inv_count += mergeSort_and_count(left, middle, numbers);
        inv_count += mergeSort_and_count(middle + 1, right, numbers);
        inv_count += merge_and_count(left, middle, right, numbers);
    }

    return inv_count;
}   

void testcase() {
    int N;
    cin >> N;
    vector<int> numbers(N);

    for (int &value : numbers) {
        cin >> value;
    }

    cout << mergeSort_and_count(0, N - 1, numbers) << '\n';
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
//CẶP NGHỊCH THẾ