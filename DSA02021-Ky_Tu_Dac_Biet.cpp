//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/10/2024

#include <iostream>

using namespace std;

//Fear is just an illusion

char findNthCharacter(const string& s, long long N) {
    long long len = s.size();
    while (N > len) {
        long long prevLen = len;
        while (prevLen * 2 < N) {
            prevLen *= 2;
        }

        if (N == prevLen + 1) {
            N--;
        } else {
            N -= (prevLen + 1);
        }
    }

    return s[N - 1];
}

void testcase() {
    string S;
    long long N;
    cin >> S >> N;

    cout << findNthCharacter(S, N) << '\n';
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
//KÝ TỰ ĐẶC BIỆT