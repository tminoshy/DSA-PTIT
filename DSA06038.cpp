#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

// Define a Binary Indexed Tree (BIT) array
int bit[1000001];

// Function to update the BIT at index i
void update(int i) {
    // Increment the value at index i and propagate the update
    for (; i < 1000001; i += i & -i)
        bit[i]++;
}

// Function to get the prefix sum up to index i in the BIT
int get(int i) {
    int s = 0;
    // Sum the values from index i down to 1
    for (; i; i -= i & -i)
        s += bit[i];
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n; // Read the number of elements

    int a[n + 1]; // Array to store the elements
    stack<int> st; // Stack to temporarily store even numbers

    // Read the elements into the array
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // Process the array from the end to the beginning
    for (int i = n; i > 0; i--) {
        if (a[i] % 2 == 0) { // If the element is even
            // Count the number of elements less than a[i] using the BIT
            ans += get(a[i] - 1);
            // Push the even element onto the stack
            st.push(a[i]);
        } else { // If the element is odd
            // Update the BIT with all elements in the stack
            while (!st.empty()) {
                update(st.top());
                st.pop();
            }
        }
    }

    // Output the result
    cout << ans << endl;
    return 0;
}