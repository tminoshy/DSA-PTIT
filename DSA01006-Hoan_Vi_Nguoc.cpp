//https://github.com/tminoshy
//created by Đỗ Thiện Minh at 17/09/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateReversePermutations(int index, int sz, vector<bool>& visited, vector<int>& currentPermutation) {
    for (int j = sz - 1; j >= 0; j--) {
        if (!visited[j]) {
            currentPermutation[index] = j + 1;
            visited[j] = true;
            if (index == sz - 1) {
                for (size_t i = 0; i < sz; i++) {
                    cout << currentPermutation[i];
                }
                cout << " ";
            } else {
                generateReversePermutations(index + 1, sz, visited, currentPermutation);
            }
            visited[j] = false;
        }
    }
}

void Testcase() {
    int N; cin >> N;
    vector<bool> visited(N, false);
    vector<int> currentPermutation(N);
    generateReversePermutations(0, N, visited, currentPermutation);
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
//HOÁN VỊ NGƯỢC
