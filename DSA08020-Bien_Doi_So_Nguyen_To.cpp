//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 27/10/2024

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

//Fear is just an illusion

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}

int BFS(string S, string T) {
    queue<pair<string, int>> q;
    unordered_set<string> visited;
    q.push({S, 0});
    visited.insert(S);
    
    while(!q.empty()) {
        auto [current, step] = q.front();
        q.pop();

        if (current == T) {
            return step;
        }

        for (int i = 0; i < 4; i++) {
            string newS = current;
            for (int j = 0; j <= 9; j++) {
                if (i == 0 && j == 0) continue;
                newS[i] = j + '0';
                if (isPrime(stoi(newS)) && visited.count(newS) == 0) {
                    q.push({newS, step + 1});
                    visited.insert(newS);
                }
            }
        }
    }
    return -1;
}

void testcase() {
    string S, T;
    cin >> S >> T;
    cout << BFS(S, T) << '\n';
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
//BIẾN ĐỔI SỐ NGUYÊN TỐ