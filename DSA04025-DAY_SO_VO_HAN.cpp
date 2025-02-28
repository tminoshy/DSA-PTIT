#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct Matrix{
    ll a[2][2];

    friend Matrix operator * (Matrix x, Matrix y){
        Matrix res;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                res.a[i][j] = 0;
                for(int k = 0; k < 2; k++){
                    res.a[i][j] += x.a[i][k] * y.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    };
};
Matrix binPow(Matrix a, ll k){
    if(k == 1){
        return a;
    }
    Matrix x = binPow(a, k / 2);
    if(k & 1){
        return a * x * x;
    }
    else return x * x;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        Matrix x;
        x.a[0][0] = 1;
        x.a[0][1] = 1;
        x.a[1][0] = 1;
        x.a[1][1] = 0;
        Matrix res = binPow(x, n);
        cout << res.a[0][1] << endl;
    }
    return 0;
}
/* No Code - No Bug */