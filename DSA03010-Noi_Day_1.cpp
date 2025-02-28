//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/09/2024

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

void testcase() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    priority_queue<int, vector<int>, greater<int>> PQ(numbers.begin(), numbers.end());
    long long cost = 0;
    while (PQ.size() > 1) {
        int first = PQ.top();
        PQ.pop();
        int second = PQ.top();
        PQ.pop();
        cost += first + second;
        PQ.push(first + second);
    }
    cout << cost << endl;
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
//NỐI DÂY 1