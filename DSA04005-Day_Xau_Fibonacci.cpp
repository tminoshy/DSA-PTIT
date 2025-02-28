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
        fiboSize[i] = fiboSize[i - 1] + fiboSize[i - 2];
    }
}

char findIth(int N, long long i) {
    if (N == 1) return 'A';
    if (N == 2) return 'B';
    /*If i is greater than the size of the (N-2)th Fibonacci string,
    it belongs to the (N-1)th Fibonacci string*/
    if (i > fiboSize[N - 2]) return findIth(N - 1, i - fiboSize[N - 2]);
    // Otherwise, it belongs to the (N-2)th Fibonacci string.
    return findIth(N - 2, i);
}

void testcase() {
    int N;
    long long i;
    cin >> N >> i;

    cout << findIth(N, i) << '\n';
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
//DÃY XÂU FIBONACCI