//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 17/09/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generatePermutations(int index, vector<int>& currentPermutation, vector<int>& visited, vector<int>& numbers) {
    for (size_t j = 0; j < numbers.size(); j++) {
        if (!visited[j]) {
            currentPermutation[index] = numbers[j];
            visited[j] = 1;
            if (index == numbers.size() - 1) {
                for (const int &value : currentPermutation) {
                    cout << value << " ";
                }
                cout << endl;
            }
            generatePermutations(index + 1, currentPermutation, visited, numbers);
            visited[j] = 0;
        }
    }
}

void solve() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int &value: numbers) {
        cin >> value;
    }
    sort(numbers.begin(), numbers.end());
    vector<int> currentPermutation(N);
    vector<int> visited(N, false);
    generatePermutations(0, currentPermutation, visited, numbers);
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//HOÁN VỊ DÃY SỐ