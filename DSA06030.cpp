//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>

using namespace std;

void Testcase() {
    int size; cin >> size;
    vector<int> myVec(size);
    for(int &x : myVec) {
        cin >> x;
    }
    vector<vector<int>> storage;
    for(int i = 0; i < size; i++) {
        bool swaped = false;
        for(int j = 1; j < size - i; j++) {
            if(myVec[j - 1] > myVec[j]) {
                swaped = true;
                swap(myVec[j - 1], myVec[j]);
            }
        }
        if(swaped) {
            storage.push_back(myVec);
        }
    }
    for(int i = storage.size() - 1; i >= 0; i--) {
        cout << "Buoc " << i + 1 << ": ";
        for(int j = 0; j < storage[i].size(); j++) {
            cout << storage[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//SẮP XẾP NỔI BỌT - LIỆT KÊ NGƯỢC