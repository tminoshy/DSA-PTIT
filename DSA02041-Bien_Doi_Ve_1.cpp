//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <queue>

using namespace std;

void testcase() {
    int N; cin >> N;
    queue<pair<int, int>> myqueue;
    myqueue.push({N, 0});
    while (true) {
        pair<int, int> current = myqueue.front();
        if (current.first == 1) {
            cout << current.second << endl;
            return;
        }
        myqueue.pop();
        if (current.first % 3 == 0) {
            myqueue.push({current.first / 3, current.second + 1});
        }
        if (current.first % 2 == 0) {
            myqueue.push({current.first / 2, current.second + 1});
        }
        myqueue.push({current.first - 1, current.second + 1});
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
//BIẾN ĐỔI VỀ 1