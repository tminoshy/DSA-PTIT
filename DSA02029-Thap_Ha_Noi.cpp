//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 13/09/2024

#include <iostream>

using namespace std;

void moveDisks(int diskCount, char fromRod, char toRod, char tempRod) {
    if (diskCount == 1) {
        cout << fromRod << " -> " << toRod << endl;
        return; 
    }
    moveDisks(diskCount - 1, fromRod, tempRod, toRod);
    cout << fromRod << " -> " << toRod << endl;
    moveDisks(diskCount - 1, tempRod, toRod, fromRod);
}

void solve() {
    int N; cin >> N;
    moveDisks(N, 'A', 'C', 'B');
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//THÁP HÀ NỘI