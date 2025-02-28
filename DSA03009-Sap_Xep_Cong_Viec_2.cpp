//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 06/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareSecond(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

void testcase() {
    int N; cin >> N;
    vector<pair<int, int>> attributes(N);
    int jobID; //discard
    int max_first = 1000000;
    for (int i = 0; i < N; i++) {
        cin >> jobID >> attributes[i].first >> attributes[i].second;
        max_first = max(max_first, attributes[i].first);
    }
    vector<bool> busy(max_first + 1, false);
    sort(attributes.begin(), attributes.end(), compareSecond);
    int count = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = attributes[i].first; j > 0; j--) {
            if (!busy[j]) {
                ans += attributes[i].second;
                busy[j] = true;
                count++;
                break;
            }
        }
    }
    cout << count << " " << ans << endl;
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
//SẮP XẾP CÔNG VIỆC 2