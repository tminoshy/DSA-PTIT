//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 27/10/2024

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//Fear is just an illusion

bool findMultiple(vector<int>& numbers, int N) {
    sort(numbers.begin(), numbers.end());
    queue<int> q0, q1, q2;

    int sumOfDigits = 0;
    for (int i = 0; i < N; i++) {
        if (numbers[i] % 3 == 0) q0.push(numbers[i]);
        else if (numbers[i] % 3 == 1) q1.push(numbers[i]);
        else q2.push(numbers[i]);

        sumOfDigits += numbers[i];
    }

    if (sumOfDigits % 3 == 1) {
        if (!q1.empty()) q1.pop();
        else {
            for (int k = 0; k <= 1; k++) {
                if (!q2.empty()) q2.pop();
                else return false;
            }
        }
    }

    if (sumOfDigits % 3 == 2) {
        if (!q2.empty()) q2.pop();
        else {
            for (int k = 0; k <= 1; k++) {
                if (!q1.empty()) q1.pop();
                else return false;
            }
        }
    }

    vector<int> result;
    while (!q0.empty()) {
        result.push_back(q0.front());
        q0.pop();
    }

    while (!q1.empty()) {
        result.push_back(q1.front());
        q1.pop();
    }

    while (!q2.empty()) {
        result.push_back(q2.front());
        q2.pop();
    }

    if (!result.empty()) {
        sort(result.rbegin(), result.rend());
        for (const int& value : result) {
            cout << value;
        }
        return true;
    }

    return false;
}

void testcase() {
    int N;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    
    if (!findMultiple(numbers, N)) {
        cout << "-1";
    }
    
    cout << '\n';
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
//BỘI SỐ LỚN NHẤT CỦA 3