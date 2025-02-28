//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/09/2024

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

void testcase() {
    int N; cin >> N;
    vector<pair<int, int>> times(N);
    for (size_t i = 0; i < N; i++) {
        cin >> times[i].first;
        cin >> times[i].second;
    } 
    sort(times.begin(), times.end(), compare);
    int count = 1;
    int process = times[0].second;
    for (size_t i = 1; i < N; i++) {
        if (times[i].first >= process) {
            process = times[i].second;
            count++;
        }
    }
    cout << count << endl;
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
//TRỤC TỌA ĐỘ