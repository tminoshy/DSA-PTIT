//https://github.com/tminoshy
//created by Đỗ Thiện Minh

#include <iostream>
#include <vector>

using namespace std;

void Testcase() {
    int size, target, ans;
    cin >> size >> target;
    for(int i = 1; i <= size; ++i) {
        int element; cin >> element;
        if(element == target) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    int testCount; cin >> testCount;
    while(testCount--) {
        Testcase();
    }
    return 0;
}

//TÌM KIẾM TRONG DÃY SẮP XẾP VÒNG