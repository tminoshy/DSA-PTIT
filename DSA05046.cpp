#include<iostream>

using namespace std;

const int MOD = 1e9 + 7;

long long n, k;
long long C[1050][1050];

long long Pow(long long a, long long n) {
	if (n == 1) return a % MOD;
	long long tmp = Pow(a, n / 2);
	if (n % 2) return ((tmp % MOD * tmp % MOD) % MOD) * a % MOD;
	return (tmp % MOD * tmp % MOD) % MOD;
}

void to_hop() {
	for (int i = 0; i < 1050; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0 || i == j)C[i][j] = 1;
			else C[i][j] = C[i - 1][j - 1] % MOD + C[i - 1][j] % MOD;
			C[i][j] %= MOD;
		}
	}
}

long long Load(long long n, long long k) {
	if (k == 0)return n % MOD;
	long long dp[1050];
	dp[0] = n % MOD;
	n %= MOD;
	long long tmp = n + 1;
	for (int i = 1; i < k + 1; i++) {
        cout << "i = " << i << '\n' << "{" << '\n';
        cout << "tmp = " << tmp << '\n';
		tmp = (tmp * (n + 1) % MOD) % MOD;
        cout << "tmp = " << tmp << '\n';
		dp[i] = (tmp - 1 + MOD) % MOD;
        cout << "dp[i] = " << dp[i] << '\n';
		long long sum = 0;
		for (int j = 0; j < i; j++) {
            sum = (sum % MOD + (dp[j] % MOD * C[i + 1][i - j + 1] % MOD) % MOD) % MOD;
            cout << "C[" << i + 1 << "][" << i - j + 1 << "]" << '\n';  
        }
        cout << "sum = " << sum <<'\n';
		sum %= MOD;
		dp[i] = (dp[i] + MOD - sum) % MOD;
        cout << "dp[i] = " << dp[i] << '\n';
		dp[i] = dp[i] * Pow(i + 1, MOD - 2) % MOD;
        cout << Pow(i + 1, MOD - 2) % MOD << '\n';
        cout << "dp[i] = " << dp[i] << '\n';
		dp[i] %= MOD;
        cout << "}" << '\n';
	}
    for (int i = 0; i <= k; i++) {
        cout << dp[i] << " ";
    }
    cout << '\n';
	return dp[k];
}

int main() {
	to_hop();
    int testcase;
    cin >> testcase;
    while (testcase--) {
        cin >> n >> k;
		cout << Load(n, k) << endl;
    }
}