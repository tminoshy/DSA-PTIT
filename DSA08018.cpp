//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 17/09/2024

#include <iostream>
#include <queue>

using namespace std;

void Testcase() {
    int n; cin >> n;
    queue<string> myqueue;
    queue<string> ans;
    int count = 0;
    myqueue.push("6");
    myqueue.push("8");
    while (1) {
        string temp = myqueue.front();
        myqueue.pop();
        if (temp.size() <= n) {
            ans.push(temp);
            count++;
        } else {
            break;
        }
        myqueue.push(temp + "6");
        myqueue.push(temp + '8');
    }
    cout << count << endl;
    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
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

//SỐ LỘC PHÁT 2