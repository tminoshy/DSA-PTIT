//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 06/10/2024

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void testcase() {
    int N; cin >> N;
    vector<int> height(N);
    for (int& value : height) {
        cin >> value;
    }
    height.push_back(0);
    stack<int> mystk;
    long long ans = 0;
    for (int i = 0; i < N + 1; i++) {
        while (!mystk.empty() && height[i] < height[mystk.top()]) {
            int currentH = height[mystk.top()];
            mystk.pop();
            int low = (mystk.empty()) ? -1 : mystk.top();
            long long current = static_cast<long long>(i - low - 1) * currentH;
            ans = max(ans, current);
        }
        mystk.push(i);
    }
    cout << ans << endl;
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
//HÌNH CHỮ NHẬT LỚN NHẤT