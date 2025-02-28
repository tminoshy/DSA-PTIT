//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 22/09/2024

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool findSubset(int index, int currentSum, int targetSum,const vector<int>& numbers) {
    if (currentSum == targetSum) return true;
    if (index == numbers.size() || currentSum > targetSum) return false;
    if (findSubset(index + 1, currentSum + numbers[index], targetSum, numbers)) return true;
    return findSubset(index + 1, currentSum, targetSum, numbers);
}

void Testcase() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int &element : numbers) {
        cin >> element;
    }
    int totalSum = accumulate(numbers.begin(), numbers.end(), 0);
    if (totalSum % 2 != 0) {
        cout << "NO" << endl;
        return;
    }
    int halfSum = totalSum / 2;
    if (findSubset(0, 0, halfSum, numbers)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
}

int main() {
    int testCount; cin >> testCount;
    while (testCount--) {
        Testcase();
    }
    return 0;
}

//TẬP CON BẰNG NHAU