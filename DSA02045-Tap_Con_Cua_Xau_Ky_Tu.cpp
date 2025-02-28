//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 06/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void GenerateSubsequences(int index, int N, string currentSubsequence, const string& S, vector<string>& result) {
    if (index == S.size()) {
        if (S.size() > 0) {
            result.push_back(currentSubsequence);
        }
        return;
    }
    if (currentSubsequence.size() > N) {
        return;
    }
    GenerateSubsequences(index + 1, N, currentSubsequence + S[index], S, result);
    GenerateSubsequences(index + 1, N, currentSubsequence, S, result);
}

void testcase() {
    int N; cin >> N;
    string S; cin >> S;
    string currentSubsequence = "";
    vector<string> result;
    GenerateSubsequences(0, N, currentSubsequence, S, result);
    sort(result.begin(), result.end());
    for (const string& str : result) {
        cout << str << " ";
    }
    cout << endl;
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
//TẬP CON CỦA XÂU KÝ TỰ