//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 17/09/2024

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void Testcase() {
    int n; cin >> n;
    queue<string> myqueue;
    stack<string> mystk;
    myqueue.push("6");
    myqueue.push("8");
    while (1) {
        string temp = myqueue.front();
        myqueue.pop();
        if (temp.length() > n) {
            break;
        }
        myqueue.push(temp + "6");
        myqueue.push(temp + "8");
        mystk.push(temp);
        
    }
    while (!mystk.empty()) {
        cout << mystk.top() << " ";
        mystk.pop();
    }
    cout << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//SỐ LỘC PHÁT 1