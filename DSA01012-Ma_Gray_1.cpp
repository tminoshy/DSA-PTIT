//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>

using namespace std;

//10101010001
//1

string convertToGray(const string& s) {
    string gray = "";
    gray += s[0];
    for (int i = 1; i < s.size(); i++) {
        gray += (s[i] == s[i - 1]) ? '0' : '1';
    }
    return gray;
}

void generate(int n, string s) {
    if (s.size() == n) {
        cout << convertToGray(s) << " ";
        return;
    }
    generate(n, s + '0');
    generate(n, s + '1');
}

void testcase() {
    int n; cin >> n;
    string s;
    generate(n, s);
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
//MÃ GRAY 1