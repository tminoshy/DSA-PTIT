//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 20/10/2024

#include <iostream>
#include <unordered_map>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

//Fear is just an illusion

void pushMap(const string& s, unordered_map<int, int>& umap) {
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            int base = 0, exp = 0;

            while (isdigit(s[i]) && i < s.length()) {
                base = base * 10 + (s[i++] - '0');
            }

            i += 3;

            while (isdigit(s[i]) && i < s.length()) {
                exp = exp * 10 + (s[i++] - '0');
            }

            umap[exp] += base;
        }
    }
}

void testcase() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    unordered_map<int, int> umap;

    pushMap(s1, umap);
    pushMap(s2, umap);

    vector<pair<int, int>> res(umap.begin(), umap.end());
    sort(res.rbegin(), res.rend());
    
    for (int i = 0; i < res.size() - 1; i++) {
        cout << res[i].second << "*x^" << res[i].first << " + ";
    }
    cout << res.back().second << "*x^" << res.back().first << '\n';

}

int main() {
    int testCaseCount;
    cin >> testCaseCount;

    cin.ignore();

    while (testCaseCount--) {
        testcase();
    }

    return 0;
}

//B23DCCE064
//TỔNG ĐA THỨC