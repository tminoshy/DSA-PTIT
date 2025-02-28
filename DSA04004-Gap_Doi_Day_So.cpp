//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/09/2024

#include <iostream>
#include <cmath>

using namespace std;

long long findKth(int N, long long K) {
    long long middle = pow(2, N - 1);
    if (K == middle) return N;
    if (K > middle) return findKth(N - 1, K - middle);
    return findKth(N - 1, K);
}

void testcase() {
    int N;
    long long K;
    cin >> N >> K;
    cout << findKth(N, K) << endl;
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
//GẤP ĐÔI DÃY SỐ