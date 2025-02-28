//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 11/10/2024

#include <iostream>
#include <vector>

using namespace std;         

void testcase() {
    int N;
    cin >> N;
    vector<int> numbers(N);

    for (int &value : numbers) {
        cin >> value;
    }

    vector<int> leftMax(N);
    leftMax[0] = numbers[0];
    for (int i = 1; i < N; i++) {
        leftMax[i] = max(leftMax[i - 1], numbers[i]);
    }

    vector<int> rightMin(N);
    rightMin[N - 1] = numbers[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        rightMin[i] = min(rightMin[i + 1], numbers[i]);
    }

    int count = 0;
    vector<int> result;
    for (int i = 1; i < N; i++) {
        if (leftMax[i - 1] <= rightMin[i]) {
            result.push_back(i);
            count++;
        }
    }

    if (count == 0) {
        cout << "0" << '\n';
        return;
    }

    cout << count << '\n';
    for (const int& value : result) {
        cout << value << " ";
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
//SẮP XẾP ĐOẠN CON