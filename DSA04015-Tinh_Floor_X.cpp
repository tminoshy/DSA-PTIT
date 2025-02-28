//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/09/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int N, X;
    cin >> N >> X;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    if (numbers[0] > X) {
        cout << "-1\n";
        return;
    }

    int front = 0, back = numbers.size() - 1;
    int floorIndex = -1;
    while (front < back) {
        int middle = front + (back - front) / 2;
        if (numbers[middle] <= X) {
            front = middle + 1;
        } else {
            back = middle;
        }
    }
    cout << front << endl;
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
//TÍNH FLOOR(X)