//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 26/09/2024

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false;
    else if (number <= 3) return true;
    else if (number % 2 == 0 || number % 3 == 0) return false;
    else {
        for (size_t i = 5; i <= sqrt(number); i += 6) {
            if (number % i == 0 || number % (i + 2) == 0) return false;
        }
    }
    return true;
}

void findNPrimeNumber(int index, int &count, int total, int currentSum, int targetSum, const vector<int> &primeNumber, vector<int> &currentPrime, vector<vector<int>> &result) {
    if (index >= primeNumber.size() || currentSum > targetSum) {
        return;
    }
    if (currentPrime.size() == total) {
        if (currentSum == targetSum) {
            result.push_back(currentPrime);
            count++;
        }
        return;
    }
    currentPrime.push_back(primeNumber[index]);
    findNPrimeNumber(index + 1, count, total, currentSum + primeNumber[index], targetSum, primeNumber, currentPrime, result);
    currentPrime.pop_back();
    findNPrimeNumber(index + 1, count, total, currentSum, targetSum, primeNumber, currentPrime, result);
}

void testcase() {
    int N, P, S;
    cin >> N >> P >> S;
    vector<int> primeNumber;
    for (size_t i = P + 1; i < S; i++) {
        if (isPrime(i)) {
            primeNumber.push_back(i);
        }
    }
    vector<int> currentPrime;
    vector<vector<int>> result;
    int count = 0;
    findNPrimeNumber(0, count, N, 0, S, primeNumber, currentPrime, result);
    cout << count << endl;
    for (const vector<int>& prime : result) {
        for (const int &i : prime) {
            cout << i << " ";
        }
        cout << endl;
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
//SỐ NGUYÊN TỐ