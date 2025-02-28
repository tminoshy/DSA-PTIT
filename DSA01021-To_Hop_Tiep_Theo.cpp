//https://github.com/tminoshy
//created by Đỗ Thiện Minh at 16/09/2024

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void Testcase() {
    int N, K;
    cin >> N >> K;
    vector<int> combination(K);
    unordered_set<int> uset;
    for (int &value : combination) {
        cin >> value;
        uset.insert(value);
    }
    int index = K - 1;
    while (index >= 0 && combination[index] == N - K + index + 1) {
        index--;
    }
    if (index >= 0) {
        combination[index]++;
        for (size_t j = index + 1; j < K; j++) {
            combination[j] = combination[index] + j - index;
        }
    } else {
        cout << K << endl;
        return;
    }
    int count = 0;
    for (const int &value : combination) {
        if (uset.find(value) == uset.end()) {
            count++;
        }
    }
    cout << count;
    cout << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//B23DCCE064
//TỔ HỢP TIẾP THEO