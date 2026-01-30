/*
2189D1
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std; 

constexpr long long MOD = 1e9+7;

int main() {
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        string s; cin >> s;
        if(s[0] == '0' || s[n-1] == '0') {
            cout << "-1\n";
            continue;
        }
        long long ans = 2;
        c/= gcd(c, 2);
        for(int i = 1; i < n-1; ++i) {
            if (s[i] == '0') {
                ans *= i;
                c/= gcd(c, i);
            }
            else {
                ans *= 2;
                c /= gcd(c, 2);
            }
            ans %= MOD;
        }

        if(c > 1) cout << ans << "\n";
        else cout << "-1\n";
    }
    return 0;
}