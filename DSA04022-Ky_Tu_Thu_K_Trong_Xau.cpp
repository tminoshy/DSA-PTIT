//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 01/10/2024

#include <iostream>
#include <cmath>

using namespace std;

char findKth(int N, long long K) {
    long long middle = pow(2, N - 1);
    if (K == middle) return N + 'A' - 1;
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
//KÝ TỰ THỨ K TRONG XÂU