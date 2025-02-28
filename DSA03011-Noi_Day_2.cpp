//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MOD = 1e9 + 7;

void testcase() {
    int N; cin >> N;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    while (N--) {
        long long value; cin >> value;
        pq.push(value);
    }
    long long ans = 0;
    while (pq.size() > 1) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        int total = (first + second) % MOD;
        pq.push(total);
        ans = (ans + total) % MOD;
    }
    cout << ans << endl;
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
//NỐI DÂY 2