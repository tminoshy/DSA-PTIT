//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/09/2024

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;
    for (int i = 5; i <= sqrt(number); i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}

void generateSubset(int depth, int currentSum, const vector<int>& numbers, vector<int>& currentSubset) {
    if (depth == numbers.size()) {
        if (isPrime(currentSum)) {
            for (const int& value : currentSubset) {
                cout << value << " ";
            }
            cout << endl;
        }
        return;
    }
    generateSubset(depth + 1, currentSum, numbers, currentSubset);
    currentSubset.push_back(numbers[depth]);
    generateSubset(depth + 1, currentSum + numbers[depth], numbers, currentSubset);
    currentSubset.pop_back();
}

void testcase() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int &value : numbers) {
        cin >> value;
    }
    sort(numbers.rbegin(), numbers.rend());
    vector<int> currentSubset;
    generateSubset(0, 0, numbers, currentSubset);
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
//DÃY CON CÓ TỔNG NGUYÊN TỐ