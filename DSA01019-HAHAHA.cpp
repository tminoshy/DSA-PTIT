//https://github.com/tminoshy
//created by Đỗ Thiện Minh at 16/09/2024

#include <iostream>
#include <vector>

using namespace std;

void generateHAHA(int index, int sz, vector<char>& sequence) {
    if (index == sz) {
        for (const char &c : sequence) {
            cout << c;
        }
        cout << endl;
        return;
    }
    if(index == 0) {
        sequence[index] = 'H';
        generateHAHA(index + 1, sz, sequence);
    } else if (index == sz - 1) {
        sequence[index] = 'A';
        generateHAHA(index + 1, sz, sequence);
    } else {
        if (sequence[index - 1] != 'H') {
            sequence[index] = 'A';
            generateHAHA(index + 1, sz, sequence);
            sequence[index] = 'H';
            generateHAHA(index + 1, sz, sequence);
        } else {
            sequence[index] = 'A';
            generateHAHA(index + 1, sz, sequence);
        }  
    }
}

void Testcase() {
    int N; cin >> N;
    vector<char> sequence(N);
    generateHAHA(0, N, sequence);
}

int main() {
    int testCount; 
    cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//B23DCCE064
//HAHAHA