//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 06/10/2024

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void testcase() {
    int n; cin >> n;
    vector<int> numbers(n);
    for (int& value : numbers) {
        cin >> value;
    }
    vector<int> nextGreater(n, -1);
    stack<int> mystk;
    for (int i = 0; i < n; i++) {
        while (!mystk.empty() && numbers[i] > numbers[mystk.top()]) {
            nextGreater[mystk.top()] = i;
            mystk.pop();
        }
        mystk.push(i);
    }
    vector<int> nextSmaller(n, -1);
    for (int i = 0;i < n; i++) {
        if (nextGreater[i] != -1) {
            for (int j = nextGreater[i] + 1; j < n; j++) {
                if (numbers[j] < numbers[nextGreater[i]]) {
                    nextSmaller[i] = numbers[j];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << nextSmaller[i] << " ";
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
//PHẦN TỬ BÊN PHẢI NHỎ HƠN