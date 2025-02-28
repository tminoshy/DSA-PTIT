//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 09/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase() {
    int N;
    cin >> N;
    vector<int> numbers(N);

    for (int &value : numbers) {
        cin >> value;
    }

    sort(numbers.begin(), numbers.end());

    int left = N / 2, right = N - 1, pairK = 0;

    while (left >= 0 && right >= N / 2) {
        if (numbers[right] >= numbers[left] * 2) {
            pairK++;
            left--;
            right--;
        } else {
            left--;
        }
    }

    cout << N - pairK << '\n';
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
//SẮP XẾP KANGURU