//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 27/10/2024

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//Fear is just an illusion

void testcase() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> height(M + 1, 0);

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 0) {
                height[j] = 0;
            } else {
                height[j]++;
            }
        }

        stack<int> mystk;
        for (int j = 0; j <= M; j++) {
            while (!mystk.empty() && height[j] < height[mystk.top()]) {
                int currentH = height[mystk.top()];
                mystk.pop();
                int low = mystk.empty() ? -1 : mystk.top();
                long long current = static_cast<long long>(j - low - 1) * currentH;
                ans = max(ans, current);
            }
            mystk.push(j);
        }
    }

    cout << ans << '\n';
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
//HÌNH CHỮ NHẬT 0-1