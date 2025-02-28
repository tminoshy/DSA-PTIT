//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void solve() {
    int size; cin >> size;
    vector<int> myVec(size);
    for(int &x : myVec) {
        cin >> x;
    }
    int count = 1;
    for(int i = 0; i < size; i++) {
        bool swaped = false;
        for(int j = 1; j < size - i; j++) {
            if(myVec[j - 1] > myVec[j]) {
                swaped = true;
                swap(myVec[j - 1], myVec[j]);
            }
        }
        if(swaped) {
            cout << "Buoc " << count++ << ": ";
            for(int value : myVec) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}

//SẮP XẾP NỔI BỌT