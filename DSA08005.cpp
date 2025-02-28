//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <queue>

using namespace std;

void Testcase() {
    int n; cin >> n;
    queue<string> myqueue;
    myqueue.push("1");
    while(n--) {
        string s = myqueue.front();
        myqueue.pop();
        myqueue.push(s + "0");
        myqueue.push(s + "1");
        cout << s << " ";
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

//SỐ NHỊ PHÂN TỪ 1 ĐẾN N