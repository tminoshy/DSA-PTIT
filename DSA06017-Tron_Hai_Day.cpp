//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/08/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Testcase() {
    int size1, size2;
    cin >> size1 >> size2;

    vector<int> vec1(size1), vec2(size2);

    for (int i = 0; i < size1; i++) {
        cin >> vec1[i];
    }

    for (int i = 0; i < size2; i++) {
        cin >> vec2[i];
    }

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    int index1 = 0, index2 = 0, i = 0;
    vector<int> merged(size1 + size2);

    while (index1 < size1 && index2 < size2) {
        if(vec1[index1] <= vec2[index2]) {
            merged[i++] = vec1[index1++];
        } else {
            merged[i++] = vec2[index2++];
        }
    }

    while (index1 < size1) {
        merged[i++] = vec1[index1++];
    }

    while (index2 < size2) {
        merged[i++] = vec2[index2++];
    }

    for (const int& value : merged) {
        cout << value << " ";
    }
    cout << '\n';
}

int main() {
    int testCount;
    cin >> testCount;

    while (testCount--) {
        Testcase();
    }

    return 0;
}

//B23DCCE064
//TRỘN HAI DÃY