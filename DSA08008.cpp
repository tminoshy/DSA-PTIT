//https://github.com/tminoshy
//created by Đỗ Thiện Minh at 17/09/2024

#include <iostream>
#include <queue>

using namespace std;

void Testcase() {
    int n; cin >> n;
    queue<string> myqueue;
    myqueue.push("1");
    int count = 0;
    while (!myqueue.empty()) {
        string temp = myqueue.front();
        myqueue.pop();
        if (stoll(temp) % n == 0) {
            cout << temp << endl;
            return;
        }
        string x = temp + "0";
        myqueue.push(x);
        x = temp + "1";
        myqueue.push(x);
    }
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//SỐ BDN 2