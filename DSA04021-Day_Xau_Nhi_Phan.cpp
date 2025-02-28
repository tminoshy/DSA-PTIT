//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/09/2024

#include <iostream>
#include <vector>

using namespace std;

vector<long long> fiboSize(93);

void initSize() {
    fiboSize[1] = 1;
    fiboSize[2] = 1;
    for (size_t i = 3; i < 93; i++) {
        fiboSize[i] = fiboSize[i - 2] + fiboSize[i - 1];
    }
}

int findKth(int N, long long K) {
    if (N == 1) return 0;
    if (N == 2) return 1;
    if (K > fiboSize[N - 2]) return findKth(N - 1, K - fiboSize[N - 2]);
    return findKth(N - 2, K);
}

void testcase() {
    int N;
    long long K;
    cin >> N >> K;
    cout << findKth(N, K) << endl;
}

int main() {
    initSize();
    int testCaseCount;
    cin >> testCaseCount;
    while (testCaseCount--) {
        testcase();
    }
    return 0;
}

//B23DCCE064
//DÃY XÂU NHỊ PHÂN