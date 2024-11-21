#include <iostream>
#include <vector>

using namespace std;

// Function to count the number of 1s in the range [L, R] using divide and conquer
int count_ones(int N, int L, int R, int start, int end) {
    if (L > end || R < start) {
        // If the range [L, R] is outside the current segment [start, end], return 0
        return 0;
    }
    if (L <= start && end <= R) {
        // If the current segment [start, end] is completely within the range [L, R]
        return N == 1 ? 1 : 0;
    }
    // Calculate the middle point
    int mid = (start + end) / 2;
    // Recursively count the number of 1s in the left and right segments
    return count_ones(N / 2, L, R, start, mid - 1) + (N % 2) + count_ones(N / 2, L, R, mid + 1, end);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, L, R;
        cin >> N >> L >> R;
        
        // Calculate the length of the sequence
        int length = 1;
        int temp = N;
        while (temp > 1) {
            length = length * 2 + 1;
            temp /= 2;
        }
        
        // Count the number of 1s in the range [L, R]
        int result = count_ones(N, L, R, 0, length - 1);
        
        // Print the result
        cout << result << endl;
    }
    return 0;
}