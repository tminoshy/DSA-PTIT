//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void Testcase() {
    int n; cin >> n;
    vector<int> myVec(n);
    unordered_map<int, int> umap;
    //int max = INT_MIN, min = INT_MAX;
    for(int i = 0; i < n; i++) {
        cin >> myVec[i];
        /*if(myVec[i] > max) {
            max = myVec[i];
        }
        if(myVec[i] < min) {
            min = myVec[i];
        }*/
        umap[myVec[i]]++;
    }
    sort(myVec.begin(), myVec.end());
    int min = myVec[0];
    int max = myVec[n - 1];
    int count = 0;
    for(int i = myVec[0]; i < myVec[n - 1]; i++) {
        if(umap[i] == 0) {
            count++;
        }
    }
    cout << count << endl;

}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//