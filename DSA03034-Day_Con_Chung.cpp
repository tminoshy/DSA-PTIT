//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 30/09/2024

#include <iostream>
#include <vector>

using namespace std;

void testcase() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> vecN(N), vecM(M), vecK(K);
    for (int& value : vecN) {
        cin >> value;
    }
    for (int& value : vecM) {
        cin >> value;
    }
    for (int& value : vecK) {
        cin >> value;
    }
    bool found = false;
    int indexN = 0, indexM = 0, indexK = 0;
    while (indexN < N && indexM < M && indexK < K) {
        if (vecN[indexN] == vecM[indexM] && vecM[indexM] == vecK[indexK]) {
            found = true;
            cout << vecN[indexN] << " ";
            indexN++;
            indexM++;
            indexK++;
        } else {
            if (vecN[indexN] < vecM[indexM]) indexN++;
            else if (vecM[indexM] < vecK[indexK]) indexM++;
            else indexK++;
        }
    }
    if (!found) cout << "NO";
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
//DÃY CON CHUNG