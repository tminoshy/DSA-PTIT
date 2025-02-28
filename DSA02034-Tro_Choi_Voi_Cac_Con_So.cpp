//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 18/09/2024

#include <iostream>
#include <vector>

using namespace std;

bool isValid(const vector<int>& permutation) {
    for (size_t i = 0; i < permutation.size() - 1; i++) {
        if (abs(permutation[i] - permutation[i + 1]) == 1) {
            return false;
        }
    }
    return true;
}

void generatePermutations(int index, int N, vector<int>& currentPermutation, vector<bool>& visited) {
    for (size_t i = 0; i < N; i++) {
        if (!visited[i]) {
            currentPermutation[index] = i + 1;
            visited[i] = true;
            if (index == N - 1) {
                if (isValid(currentPermutation)) {
                    for (int element : currentPermutation) {
                        cout << element;
                    }
                    cout << endl;
                }
            } else {
            generatePermutations(index + 1, N, currentPermutation, visited);
            }
            visited[i] = false;
        } 
    }
}

void Testcase() {
    int N; cin >> N;
    vector<bool> visited(N, false);
    vector<int> currentPermutation(N);
    generatePermutations(0, N, currentPermutation, visited);
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//B23DCCE064
//TRÒ CHƠI VỚI CÁC CON SỐ