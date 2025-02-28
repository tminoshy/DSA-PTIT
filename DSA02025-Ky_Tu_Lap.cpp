//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 29/09/2024

#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <algorithm>

using namespace std;

int countOverlap(string a, string b){
    int frequency[26] = {0};
    int cnt = 0;
    for(char c : a){
        frequency[c - 'A']++;
    }
    for(char c : b){
        frequency[c - 'A']++;
    }
    for(int it : frequency){
        if(it == 2){
            cnt++;
        }
    }
    return cnt;
}

void calculateMinOverlap(int index, vector<string> &myStrings, int &minOverlap, int currentOverlap) {
    if (currentOverlap >= minOverlap) {
        return;
    }
    if (index == myStrings.size()) {
        minOverlap = currentOverlap;
        return;
    }
    for (size_t i = index; i < myStrings.size(); i++) {
        swap(myStrings[index], myStrings[i]);
        int newOverlap = currentOverlap;
        if (index > 0) {
            newOverlap += countOverlap(myStrings[index - 1], myStrings[index]);
        }
        calculateMinOverlap(index + 1, myStrings, minOverlap, newOverlap);
        swap(myStrings[i], myStrings[index]);
    }
}

void solve() {
    int N; cin >> N;
    vector<string> myStrings(N);
    for (string &s : myStrings) {
        cin  >> s;
    }
    int minRepeat = INT_MAX;
    calculateMinOverlap(0, myStrings, minRepeat, 0);
    cout << minRepeat << endl;
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//KÝ TỰ LẶP