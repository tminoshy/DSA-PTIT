//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 20/10/2024

#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//Fear is just an illusion

vector<int> generate() {
    vector<int> validNumber;
    queue<int> q;

    for (int i = 1; i <= 5; i++) {
        q.push(i);
        validNumber.push_back(i);
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i <= 5; i++) {
            int newNumber = current * 10 + i;
            int temp = newNumber;

            unordered_set<int> digits;
            bool valid = true;
            while (temp != 0) {
                int digit = temp % 10;
                if (digit > 5 || !digits.insert(digit).second) {
                    valid = false;
                    break;
                } else {
                    digits.insert(digit);
                }
                temp /= 10;
            }
            if (valid) {
                q.push(newNumber);
                validNumber.push_back(newNumber);
            }
        }
    }

    return validNumber;
}

void testcase(const vector<int>& validNumber) {
    int L, R;
    cin >> L >> R;
    
    cout << (upper_bound(validNumber.begin(), validNumber.end(), R) - lower_bound(validNumber.begin(), validNumber.end(), L)) << '\n';
}

int main() {
    int testCaseCount;
    cin >> testCaseCount;

    vector<int> validNumber = generate();

    while (testCaseCount--) {
        testcase(validNumber);
    }
    return 0;
}

//B23DCCE064
//TÌM SỐ K THỎA MÃN ĐIỀU KIỆN