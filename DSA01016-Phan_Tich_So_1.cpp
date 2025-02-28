//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 05/10/2024

#include <iostream>
#include <vector>

using namespace std;

void generate(int N, int max, vector<int> current) {
    if (N == 0) {
        cout << "(";
        for (int i = 0; i < current.size(); i++) {
            cout << current[i];
            if (i < current.size() - 1) {
                cout << " ";
            }
        }
        cout << ") ";
    }
    for (int i = max; i > 0; i--) {
        if (N >= i) {
            current.push_back(i);
            generate(N - i, i, current);
            current.pop_back();
        } 
    }
}

void testcase() {
    int N; cin >> N;
    generate(N, N, {});
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
//PHÂN TÍCH SỐ 1