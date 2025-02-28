//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 16/10/2024

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void testcase() {
	int N;
	cin >> N;

	vector<int> numbers(N);
	for (int &value : numbers) {
		cin >> value;
	}

	stack<int> mystk;
	vector<int> ans(N);

	for (int i = 0; i < N; i++) {
		while (!mystk.empty() && numbers[mystk.top()] <= numbers[i]) {
			mystk.pop();
		}
		if (mystk.empty()) {
			ans[i] = i + 1;
		} else {
			ans[i] = i - mystk.top();
		}
		mystk.push(i);
	}

	for (const int &value : ans) {
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
//NHỊP CHỨNG KHOÁN