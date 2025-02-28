//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

void Testcase() {
    string s, sl;
    getline(cin, sl);
    stringstream ss(sl);
    stack<string> st;
    while (ss >> s) {
        st.push(s);
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    int testCount; cin >> testCount;
    cin.ignore();
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//ĐẢO TỪ