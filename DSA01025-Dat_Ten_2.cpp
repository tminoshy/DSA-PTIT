//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 17/09/2024

#include <iostream>
#include <vector>

using namespace std;

void generateCombinations(int index,int N, int K, vector<char>& currentCombination, const vector<char>& alphabet) {
    if (currentCombination.size() == K) {
        for (const char &x : currentCombination) {
            cout << x;
        }
        cout << endl;
        return;
    }
    if (index > N - 1) {
        return;
    }
    currentCombination.push_back(alphabet[index]);
    generateCombinations(index + 1, N, K, currentCombination, alphabet);
    currentCombination.pop_back();
    generateCombinations(index + 1, N, K, currentCombination, alphabet);
}

void Testcase() {
    int N, K;
    cin >> N >> K;
    vector<char> alphabet(N);
    char c = 'A';
    for (size_t i = 0; i < N; i++) {
        alphabet[i] = c++;
    }
    vector<char> currentCombination;
    generateCombinations(0, N, K, currentCombination, alphabet);
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
//ĐẶT TÊN - 2