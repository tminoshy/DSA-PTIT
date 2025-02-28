//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <deque>

using namespace std;

void solve() {
    deque<int> mydq;
    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        if(s == "PUSHFRONT") {
            cin >> s;
            mydq.push_front(stoi(s));
        } else if(s == "PRINTFRONT") {
            if(mydq.empty()) {
                cout << "NONE" << endl;
            } else {
                cout << mydq.front() << endl;
            }
        } else if(s == "POPFRONT") {
            if(!mydq.empty()) {
                mydq.pop_front();
            }
        } else if(s == "PUSHBACK") {
            cin >> s;
            mydq.push_back(stoi(s));
        } else if(s == "PRINTBACK") {
            if(mydq.empty()) {
                cout << "NONE" << endl;
            } else {
                cout << mydq.back() << endl;
            }
        } else if(s == "POPBACK") {
            if(!mydq.empty()) {
                mydq.pop_back();
            }
        }
    }
}

int main() {
    solve();
    return 0;
}

//