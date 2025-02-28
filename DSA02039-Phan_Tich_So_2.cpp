//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <vector>

using namespace std;

void generate(int remain, int max, vector<int>& current, vector<vector<int>>& result) {
    if (remain == 0) {
        result.push_back(current);
        return;
    }
    for (int i = max; i > 0; i--) {
        if (remain >= i) {
            current.push_back(i);
            generate(remain - i, i, current, result);
            current.pop_back();
        }
    }
}

void testcase() {
    int N; cin >> N;
    vector<int> current;
    vector<vector<int>> result;
    generate(N, N, current, result);
    cout << result.size() << endl;
    for (const vector<int>& vec : result) {
        cout << "(";
        for (int i = 0; i < vec.size() - 1; i++) {
            cout << vec[i] << " ";
        }
        cout << vec.back() << ") ";
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
//PHÂN TÍCH SỐ 2