//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 21/10/2024

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

//Fear is just an illusion

void testcase() {
    int N;
    cin >> N;

    vector<int> numbers(N);
    unordered_map<int, int> umap;
    
    for (int& value : numbers) {
        cin >> value;
        umap[value]++;
    }

    stack<int> mystk;
    vector<int> result(N, -1);

    for (int i = N - 1; i >= 0; i--)
        {
            while (mystk.size() && umap[mystk.top()] <= umap[numbers[i]])
                mystk.pop();
            if (!mystk.empty()) {
                result[i] = mystk.top();
            }

            mystk.push(numbers[i]);
        }

    for (const int& value : result) {
        cout << value << " ";
    }
    cout << '\n';
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
//PHẦN TỬ CÓ SỐ LẦN XUẤT HIỆN NHIỀU HƠN BÊN PHẢI