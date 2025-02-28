//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <algorithm>

using namespace std;

void testcase() {
    int n; cin >> n;
    string s; cin >> s;
    cout << n << " ";

    //std::next_permutation
    /*if (next_permutation(s.begin(), s.end())) {
        cout << s << endl;
    } else {
        cout << "BIGGEST" << endl;
    }*/

    int i = s.size() - 2;
    while (s[i] >= s[i + 1]) {
        i--;
    }
    if (i < 0) {
        cout << "BIGGEST\n";
        return;
    }
    int j = s.size() - 1;
    while (s[j] <= s[i]) {
        j--;
    }
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
    cout << s << endl;
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
//HOÁN VỊ TIẾP THEO CỦA CHUỖI SỐ