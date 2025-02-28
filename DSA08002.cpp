//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <queue>

using namespace std;

void solve() {
    queue<int> myqueue;
    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        if(s == "PUSH") {
            cin >> s;
            myqueue.push(stoi(s));
        } else if(s == "POP") {
            if(!myqueue.empty()) {
                myqueue.pop();
            }
        } else if(s == "PRINTFRONT") {
            if(myqueue.empty()) {
                cout << "NONE" << endl;
            } else {
                cout << myqueue.front() << endl;
            }
        }

    }
}

int main() {
    solve();
    return 0;
}

//CẤU TRÚC DỮ LIỆU HÀNG ĐỢI 2