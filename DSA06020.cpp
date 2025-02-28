//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>

using namespace std;

void Testcase() {
    int size; cin >> size;
    vector<int> myVec(size);
    int target; cin >> target;
    bool found = false;
    for(int i = 0; i < size; i++) {
        cin >> myVec[i];
        if(myVec[i] == target) {
            found = true;
        }
    }
    if(found) {
        cout << "1" << endl;
        return;
    }
    cout << "-1" << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//TÌM KIẾM