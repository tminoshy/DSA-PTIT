//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 17/09/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countRank(vector<int>& currentPermutation, vector<int>& targetPermutation) {
    int count = 1;
    while (!equal(currentPermutation.begin(), currentPermutation.end(), targetPermutation.begin())) {
        count++;
        int i = currentPermutation.size() - 2;
        while (i >= 0 && currentPermutation[i] > currentPermutation[i + 1]) {
            i--;
        }
        int j = currentPermutation.size() - 1;
        while (j > i && currentPermutation[i] > currentPermutation[j]) {
            j--;
        }
        swap(currentPermutation[j], currentPermutation[i]);
        reverse(currentPermutation.begin() + i + 1, currentPermutation.end());
    }
    return count;
}

void Testcase() {
    int N;  cin >> N;
    vector<int> targetPermutation(N);
    for (int &x : targetPermutation) {
        cin >> x;
    }
    vector<int> currentPermutation(N);
    for (size_t i = 0; i < N; i++) {
        currentPermutation[i] = i + 1;
    }
    cout << countRank(currentPermutation, targetPermutation) << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//B23DCCE064
//SỐ THỨ TỰ HOÁN VỊ