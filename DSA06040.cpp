//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 17/09/2024

#include <iostream>
#include <vector>   

using namespace std;

void Testcase() {
    int size1, size2, size3;
    cin >> size1 >> size2 >> size3;
    vector<int> vec1(size1), vec2(size2), vec3(size3);
    for (int &x : vec1) {
        cin >> x;
    }
    for (int &x : vec2) {
        cin >> x;
    }
    for (int &x : vec3) {
        cin >> x;
    }
    int index1 = 0, index2 = 0, index3 = 0;
    bool found = false;
    while (index1 < size1 && index2 < size2 && index3 < size3) {
        if (vec1[index1] == vec2[index2] && vec2[index2] == vec3[index3]) {
            cout << vec1[index1] << " ";
            found = true;
            index1++;
            index2++;
            index3++;
        } else if (vec1[index1] < vec2[index2]) {
            index1++;
        } else if (vec2[index2] < vec3[index3]) {
            index2++;
        } else {
            index3++;
        }
    }
    if (!found) {
        cout << "-1";
    }
    cout << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//GIAO CỦA BA DÃY SỐ