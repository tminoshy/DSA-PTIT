//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 07/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Overload the * operator to multiply a string representing a large number by an integer
string operator*(string a, int b) {
    if (a == "0" || b == 0) {
        return "0";
    }
    int n = a.size();
    string res(n, '0');
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        carry += (a[i] - '0') * b;
        res[i] = carry % 10 + '0';
        carry /= 10;
    }
    if (carry > 0) {
        res = to_string(carry) + res;
    }
    return res;
}

//Fomula : C(n) = (2n)! / (n! * (n + 1)!)

void testcase() {
    int n; cin >> n;
    // Create a vector to store the numerator values for the Catalan number formula
    vector<int> numerator;
    for (int i = n + 2; i <= 2 * n; i++) {
        numerator.push_back(i);
    }
    // Simplify the numerator by dividing by the denominator values
    for (int i = 2; i <= n; i++) {
        int denominator = i;
        for (int& value : numerator) {
            int gcd = __gcd(value, denominator);
            value /= gcd; // Simplify the numerator value
            denominator /= gcd; // Simplify the denominator value
            if (denominator == 1) {
                break; // If the denominator value is fully simplified, break
            }
        }
    }
    string result = "1";
    // Multiply all the simplified numerator values to get the final result
    for (int i = 0; i < numerator.size(); i++) {
        result = result * numerator[i];
    }
    cout << result << endl;
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
//CATALAN NUMBER