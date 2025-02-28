//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 18/09/2024

#include <iostream>
#include <vector>

using namespace std;

void generatePermutations(int index, vector<bool>& visited, vector<char>& currentPermutation, const string& S) {
    for (size_t i = 0; i < S.size(); i++) {
        if (!visited[i]) {
            currentPermutation[index] = S[i];
            visited[i] = true;
            if (index == S.size() - 1) {
                for (size_t i = 0; i < S.size(); i++) {
                    cout << currentPermutation[i];
                }
                cout << " ";
            }
            generatePermutations(index + 1, visited, currentPermutation, S);
            visited[i] = false;
        }
    }
}

void testcase() {
    string S; cin >> S;
    vector<bool> visited(S.size(), 0);
    vector<char> currentPermutation(S.size());
    generatePermutations(0, visited, currentPermutation, S);
    cout << endl;
}

int main() {
    int testCaseCount; cin >> testCaseCount;
    while(testCaseCount--) {
        testcase();
    }
    return 0;
}

//B23DCCE064
//HOÁN VỊ XÂU KÝ TỰ