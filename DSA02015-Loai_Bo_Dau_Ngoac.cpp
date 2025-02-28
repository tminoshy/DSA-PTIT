//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 24/10/2024

#include <iostream>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

//Fear is just an illusion

bool isValid(const string& S) {
    if (!S.size()) return false;
    
    int x = 0, y = 0;
    for (const char& c : S) {
        if (c == '(') {
            x++;
            y++;
        } else if (c == ')') {
            x--;
        }

        if (x < 0) return false;
    }

    if (y == 0 && S.length() == 1) return false;
    return x == 0;
}

void BFS(const string& S, vector<string>& result) {
    if (!S.length()) return;
    unordered_set<string> uset;
    queue<string> q;
    uset.insert(S);
    q.push(S);
    bool done = false;

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (isValid(current)) {
            done = true;
            result.push_back(current);
        }
        
        if (done) continue;

        for (int i = 0; i < current.length(); i++) {
            if (current[i] == '(' || current[i] == ')') {
                string newStr = current.substr(0, i) + current.substr(i + 1, current.length());
                if (uset.count(newStr) == 0) {
                    uset.insert(newStr);
                    q.push(newStr);
                }
            }
        }

    }
}

void testcase() {
    string S;
    cin >> S;
    
    vector<string> result;
    BFS(S, result);

    sort(result.begin(), result.end());

    if (!result.size()) {
        cout << "-1" << '\n';
        return;
    }

    for (const string& str : result) {
        cout << str << " ";
    }

    cout << '\n';
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
//LOẠI BỎ DẤU NGOẶC