//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 06/10/2024

#include <iostream>
#include <vector>

using namespace std;

void Try(int i, int hiddenNumCount, vector<int> vec, const string& s, bool& done) {
    if (done) {
        return;
    }
    for (int j = 0; j <= 9; j++) {
        vec.push_back(j);
        if (i == hiddenNumCount) {
            string newS = s;
            int index = 0;
            for (int k = 0; k < newS.size(); k++) {
                if (newS[k] == '?' && k != 3) {
                    newS[k] = vec[index++] + '0';
                }
            }
            if (newS[0] != '0' && newS[5] != '0' && newS[10] != '0') {
                int a = stoi(newS.substr(0, 2));
                int b = stoi(newS.substr(5, 2));
                int c = stoi(newS.substr(10, 2));
                if (newS[3] == '+') {
                    if (a + b == c) {
                        cout << newS << endl;
                        done = true;
                        return;
                    }
                } else if (newS[3] == '-') {
                    if (a - b == c) {
                        cout << newS << endl;
                        done = true;
                        return;
                    }
                } else if (newS[3] == '*') {
                    if (a * b == c) {
                        done = true;
                        cout << newS << endl;
                        return;
                    }
                } else if (newS[3] == '/') {
                    if (a / b == c) {
                        done = true;
                        cout << newS << endl;
                        return;
                    }
                } else if (newS[3] == '?') {
                    if (a + b == c) {
                        newS[3] = '+';
                        done = true;
                        cout << newS << endl;
                        return;
                    } else if (a - b == c) {
                        newS[3] = '-';
                        done = true;
                        cout << newS << endl;
                        return;
                    }
                }
            }
        }
        if (i < hiddenNumCount) {
            Try(i + 1, hiddenNumCount, vec, s, done);
        }
        vec.pop_back();
    }
}

void testcase() {
    string s;
    getline(cin, s);
    int hiddenNumCount = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?' && i != 3) {
            hiddenNumCount++;
        }
    }
    bool done = false;
    vector<int> vec;
    Try(0, hiddenNumCount, vec, s, done);
    if (!done) {
        cout << "WRONG PROBLEM!\n";
    }
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
//PHÉP TOÁN CƠ BẢN