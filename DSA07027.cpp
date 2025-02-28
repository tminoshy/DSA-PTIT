//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void Testcase() {
    int sz; cin >> sz;
    vector<int> nums(sz);
    for (int &x : nums) {
        cin >> x;
    }
    vector<int> ans(sz, -1);
    stack<int> mystk;
    for (int i = 0; i < sz; i++) {
        while (!mystk.empty() && nums[mystk.top()] < nums[i]) {
            ans[mystk.top()] = nums[i];
            mystk.pop();
        }
        mystk.push(i);
    }
    for (int x : ans) {
        cout << x << " ";
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