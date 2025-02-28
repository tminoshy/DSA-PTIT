//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 06/10/2024

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void testcase() {
    string S; cin >> S;
    //vector
    /*vector<short> numbers;
    int flag;
    if (S[0] == 'I') {
        numbers.push_back(1);
        numbers.push_back(2);
        flag = 1;
    } else {
        numbers.push_back(2);
        numbers.push_back(1);
        flag = 0;
    }
    int max = 3;
    for (int i = 1; i < S.size(); i++) {
        if (S[i] == 'I') {
            numbers.push_back(max++);
            flag = i + 1;
        } else {
            numbers.push_back(numbers[i]);
            for (int j = flag; j <= i; j++) {
                numbers[j]++;
            }
            max++;
        }
    }
    for (const int& value : numbers) {
        cout << value;
    }*/
    stack<int> pending;
    S += 'I';
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'D') {
            pending.push(i + 1);
        } else {
            cout << i + 1;
            while (!pending.empty()) {
                cout << pending.top();
                pending.pop();
            }
        }
    }
    cout << endl;
}

int main() {
    int testCaseCount;
    cin >> testCaseCount;
    while (testCaseCount--) {
        testcase();
    }
    return 0;
}

//B23DCCE064
//BIỂU THỨC TĂNG GIẢM