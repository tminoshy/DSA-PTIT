#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const long long INF = 1e18;
vector<int> primes;

// Sieve of Eratosthenes to generate prime numbers
void sieve(int max_n) {
    vector<bool> is_prime(max_n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= max_n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= max_n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

// Backtracking to find the smallest number with exactly N divisors
void find_min_number(int idx, int n, long long current, long long &result, int divisors) {
    if (divisors == n) {
        result = min(result, current);
        return;
    }
    if (idx >= primes.size() || divisors > n) return;

    long long prime_power = 1;
    for (int i = 0; ; ++i) {
        if (current > INF / prime_power) break;
        find_min_number(idx + 1, n, current * prime_power, result, divisors * (i + 1));
        if (prime_power > INF / primes[idx]) break;
        prime_power *= primes[idx];
    }
}

int main() {
    sieve(100); // Generate primes up to 100

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        long long result = INF;
        find_min_number(0, N, 1, result, 1);
        cout << result << endl;
    }

    return 0;
}