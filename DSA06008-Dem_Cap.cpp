//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 21/08/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countPair(const vector<int> &v, const vector<int> &count, int x) {
    if (x == 0) return 0;
    if (x == 1) return count[0];
    int ans = v.end() - upper_bound(v.begin(), v.end(), x);
    ans += count[1] + count[0];
    if(x == 2) ans -= count[3] + count[4];
    if(x == 3) ans += count[2];
    return ans;
} 

void Testcase() {
    int m, n; 
    cin >> m >> n;
    vector<int> nums1(m);
    vector<int> nums2(n);
    vector<int> appear(5, 0);

    for (int &element : nums1) {
        cin >> element;
    }
    for (int &element : nums2) {
        cin >> element;
    }

    sort(nums2.begin(), nums2.end());

    for(int i : nums2) {
        if(i < 5) {
            appear[i]++;
        }
    }

    int ans = 0;
    for(int i = 0; i < m; i++) {
        ans += countPair(nums2, appear, nums1[i]);
    }

    cout << ans << '\n';
}

int main() {
    int testCount; 
    cin >> testCount;

    while (testCount--) {
        Testcase();
    }

    return 0;
}

//B23DCCE064
//ĐẾM CẶP