#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    long long res = 0, tmp = 1;

    // Iterate through the string from the second character to the end
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            // If the current character is the same as the previous one, increment tmp
            tmp++;
            // Add to res the difference between the current index and tmp if tmp is less than or equal to the index
            res += i - (tmp <= i);
        } else {
            // If the current character is different, add to res the difference between the current index and tmp
            res += i - tmp;
            // Reset tmp to 1
            tmp = 1;
        }s
    }

    cout << res << endl;
    return 0;
}