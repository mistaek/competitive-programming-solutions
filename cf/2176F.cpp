/*
2176F
AC with editorial: learn how to compute num of pairs with gcd g
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std; 

long long MOD = 998244353;

long long binexp(long long a, long long e) {
    long long pow = a, ans = 1;
    for(int i = 0; i < 30; ++i) {
        if(e & (1 <<i)) ans = 1LL * ans * pow % MOD;
        pow = 1LL * pow * pow % MOD;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> sieve(2e5+1, 0), pcnt(2e5+1, 0);
    sieve[0] = sieve[1] = 1;
    for(int i =2; i <= 2e5; ++i) {
        if(sieve[i] == 0) {
            for(int j = i; j <= 2e5; j+=i) sieve[j] = i;
        }
    }

    for(int i = 2; i <= 2e5; ++i){
        int copy = i;
        while(copy != 1) {
            int lowfac = sieve[copy];
            while(copy % lowfac == 0) copy/=lowfac;
            ++pcnt[i];
        }
    }

    int t; cin >> t;
    while(t--) {
        int n, ik; cin >> n >> ik;
        vector<int> acnt(n+1, 0);
        for(int i = 0; i < n; ++i) {
            int a; cin >> a;
            acnt[a]++;
        }
        long long ans = 0;

        vector<vector<long long>> aux(n+1, vector<long long>(13, 0)), dp(n+1, vector<long long>(13,0));
        for(int i = 1; i <= n; ++i) {
            for(int j = i; j <= n; j+=i){
                aux[i][pcnt[j]] += acnt[j];
            }
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 7; ++j) {
                for(int k = j+1; k < 7; ++k) {
                    dp[i][j+k] += aux[i][j] * aux[i][k];
                }
                dp[i][2*j] += (aux[i][j] * (aux[i][j]-1))/2;
            }
        }

        for(int i = n; i >=1; --i) {
            for(int j = 2*i; j <= n; j+=i) {
                for(int k = 0; k < 13; ++k) dp[i][k] -= dp[j][k];
            }
            for(int k = 0; k < 13; ++k) {
                ans += dp[i][k] % MOD * binexp(k - pcnt[i], ik) % MOD;
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}