//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <string>
#include <queue>

using namespace std;

void findMultiples(int N) {
    queue<string> myqueue;
    myqueue.push("9");
    while (!myqueue.empty()) {
        string current = myqueue.front();
        myqueue.pop();
        if (stoll(current) % N == 0) {
            cout << current << endl;
            return;
        }
        myqueue.push(current + '0');
        myqueue.push(current + '9');
    }
}

void testcase() {
    int N; cin >> N;
    string multiples = "";
    bool done = false;
    findMultiples(N);
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
//TÌM BỘI SỐ