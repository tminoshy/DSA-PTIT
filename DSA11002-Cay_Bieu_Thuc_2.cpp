//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 06/10/2024

#include <iostream>
#include <vector>

using namespace std;

int solve(int i, const vector<string>& P) {
    if (P[i] == "+" || P[i] == "-" || P[i] == "*" || P[i] == "/") {
        if (P[i] == "+") {
            return solve(i * 2 + 1, P) + solve(i * 2 + 2, P);
        } else if (P[i] == "-") {
            return solve(i * 2 + 1, P) - solve(i * 2 + 2, P);
        } else if (P[i] == "*") {
            return solve(i * 2 + 1, P) * solve(i * 2 + 2, P);
        } else if (P[i] == "/") {
            return solve(i * 2 + 1, P) / solve(i * 2 + 2, P);
        }
    }
    return stoi(P[i]);
}

void testcase() {
    int N; cin >> N;
    vector<string> P(N);
    for (string& str : P) {
        cin >> str;
    }
    cout << solve(0, P) << endl;
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
//CÂY BIỂU THỨC 2