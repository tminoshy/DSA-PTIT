//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/08/2024

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

void Testcase() {
    int size1, size2;
    cin >> size1 >> size2;
    vector<int> vec1(size1);
    vector<int> vec2(size2);
    unordered_map<int, int> storage;

    for (int i = 0; i < size1; i++) {
        cin >> vec1[i];
        storage[vec1[i]]++;
    }
    for (int i = 0; i < size2; i++) {
        cin >> vec2[i];
        storage[vec2[i]]++;
    }

    vector<int> intersection;
    vector<int> unionV;

    for (const auto &x : storage) {
        unionV.push_back(x.first);
        if(x.second > 1) {
            intersection.push_back(x.first);
        }
    }

    sort(unionV.begin(), unionV.end());
    sort(intersection.begin(), intersection.end());

    for (const int &value : unionV) {
        cout << value << " ";
    }
    cout << '\n';

    for (const int &value : intersection) {
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
//HỢP VÀ GIAO CỦA HAI DÃY SỐ 1