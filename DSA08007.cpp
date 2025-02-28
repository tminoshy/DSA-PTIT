//https://github.com/tminoshy
//created by Đỗ Thiện Minh at 17/09/2024

#include <iostream>
#include <queue>

using namespace std;

void Testcase() {
    string number; cin >> number; 
    queue<string> myqueue;
    myqueue.push("1");
    int count = 0;
    while (!myqueue.empty()) {
        string temp = myqueue.front();
        myqueue.pop();
        count++;
        string x = temp + "0";
        if (number.size() < x.size() || number.size() == x.size() && number < x) {
            break;
        }
        myqueue.push(x);
        x = temp + "1";
        if (number.size() < x.size() || number.size() == x.size() && number < x) {
            break;
        }
        myqueue.push(x);
    }
    cout << count + myqueue.size() << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//SỐ BDN 1