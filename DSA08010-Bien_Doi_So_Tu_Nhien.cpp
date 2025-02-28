//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 09/10/2024

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

void testcase() {
    int N; 
    cin >> N;

    unordered_set<int> visited;
    queue<pair<int, int>> q;

    visited.insert(N);
    q.push({N, 0});

    while (!q.empty()) {
        auto [current, step] = q.front();
        q.pop();

        if (current == 1) {
            cout << step << '\n';
            return;
        }
        
        for (int i = 2; i * i <= current; i++) {
            if (current % i == 0 && visited.count(current / i) == 0) {
                    q.push({current / i, step + 1});
                    visited.insert(current / i);
            }
        }

        if (visited.count(current - 1) == 0) {
            q.push({current - 1, step + 1});
            visited.insert(current - 1);
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
//BIẾN ĐỔI SỐ TỰ NHIÊN