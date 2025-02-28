//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <queue>

using namespace std;

void Testcase() {
    queue<string> myqueue;
    myqueue.push("9");
    int x; cin >> x;
    while(1) {
        string s = myqueue.front();
        myqueue.pop();
        myqueue.push(s + "0");
        myqueue.push(s + "9");
        if(stoll(s) % x == 0) {
            cout << stoll(s) << endl;
            break;
        }
    }
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

// 