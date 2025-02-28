//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/10/2024

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

//Fear is just an illusion

void testcase() {
    int n;
    string src, dest;
    cin >> n >> src >> dest;

    unordered_set<string> uset;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        uset.insert(s);
    }

    queue<pair<string, int>> q;
    q.push({src, 1});
    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();
        if (current == dest) {
            cout << steps << '\n';
            return;
        }

        for (int i = 0; i < current.length(); i++) {
            string newS = current;
            for (char j = 'A'; j <= 'Z'; j++) {
                newS[i] = j;
                if (uset.count(newS) == 1) {
                    uset.erase(newS);
                    q.push({newS, steps + 1});
                }
            }
        }
    }
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
//KHOẢNG CÁCH XÂU KÝ TỰ