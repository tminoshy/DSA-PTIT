//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int N; cin >> N;
    vector<int> numbers(N);
    for (int& value : numbers) {
        cin >> value;
    }
    if (numbers[0] == 1) {
        cout << "0\n";
        return;
    }
    int front = 0, back = numbers.size();
    int floorIndex = -1;
    while (front < back) {
        int middle = front + (back - front) / 2;
        if (numbers[middle] < 1) {
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
//DSA04018