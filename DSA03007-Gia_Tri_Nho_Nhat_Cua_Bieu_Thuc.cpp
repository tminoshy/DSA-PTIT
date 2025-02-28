//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase() {
    int N; cin >> N;
    vector<long long> vec1(N), vec2(N);
    for (long long& value : vec1) {
        cin >> value;
    }
    for (long long& value : vec2) {
        cin >> value;
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.rbegin(), vec2.rend());
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += vec1[i] * vec2[i];
    }
    cout << sum << endl;
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
//GIÁ TRỊ NHỎ NHẤT CỦA BIỂU THỨC