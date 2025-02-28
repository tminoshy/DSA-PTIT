//https://github.com/tminoshy
//created by Đỗ Thiện Minh IN 04/10/2024

#include <iostream>
#include <vector>

using namespace std;

void generate(int K, int N, string currentABstr, vector<string>& result, int& count) {
    if (currentABstr.size() == N) {
        string x(K, 'A');
        int index = currentABstr.find(x, 0);
        if (index != -1) {
            string sub = currentABstr.substr(index + 1);
            if (sub.find(x) == -1) {
                result.push_back(currentABstr);
                count++;
            }
        }
        return;
    }
    generate(K, N, currentABstr + 'A', result, count);
    generate(K, N, currentABstr + 'B', result, count);
}

void solve() {
    int N, K;
    cin >> N >> K;
    string currentABstr;
    vector<string> result;
    int count = 0;
    generate(K, N, currentABstr, result, count);
    cout << count << endl;
    for (const string& str : result) {
        cout << str << endl;
    }
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//XÂU AB ĐẶC BIỆT