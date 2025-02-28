//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 18/09/2024

#include <iostream>
#include <vector>

using namespace std;

void generateStrings(int index, int length, string& current, const vector<char>& availableChars) {
    if (current.size() == length) {
        cout << current << endl;
        return;
    }
    for (size_t i = index; i < availableChars.size(); i++) {
        current.push_back(availableChars[i]);
        generateStrings(i, length, current, availableChars);
        current.pop_back();
    }
}

void solve() {
    char endChar; 
    int K;
    cin >> endChar >> K;

    vector<char> availableChars;
    for (char c = 'A'; c <= endChar; c++) {
        availableChars.push_back(c);
    }

    string current = "";
    generateStrings(0, K, current, availableChars);
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//LIỆT KÊ XÂU KÝ TỰ