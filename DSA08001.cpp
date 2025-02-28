//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <queue>

using namespace std;

void Testcase() {
    queue<int> myqueue;
    int n; cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s == "1") {
            cout << myqueue.size() << endl;
        } else if(s == "2") {
            if(myqueue.empty()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if(s == "3") {
            cin >> s;
            myqueue.push(stoi(s));
        } else if(s == "5") {
            if(myqueue.empty()) {
                cout << "-1" << endl;
            } else {
                cout << myqueue.front() << endl;
            }
        } else if(s == "6") {
            if(myqueue.empty()) {
                cout << "-1" << endl;
            } else {
                cout << myqueue.back() << endl;
            }
        } else if(s == "4") {
            if(myqueue.empty()) {
                continue;
            }
            myqueue.pop();
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

//CẤU TRÚC DỮ LIỆU HÀNG ĐỢI 1