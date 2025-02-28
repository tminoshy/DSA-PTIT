//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 15/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a <= b;
}

void testcase() {
    int N; 
    cin >> N;

    vector<int> nodeVal(N);
    for (int &value : nodeVal) {
        cin >> value;
    }

    cout << is_sorted(nodeVal.begin(), nodeVal.end(), compare) << '\n';
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
//KIỂM TRA CÂY NHỊ PHÂN TÌM KIẾM