/*
2189D2
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
            else if(s[i] == '1'){
                ans *= 2;
                c /= gcd(c, 2);
            }
            ans %= MOD;
        }
        
        for(int i = n-2; i >= 1; --i) {
            if(s[i] == '?' && (i%2) == 0) {
                // pre divide these
                s[i] = '1';
                c /= gcd(c, 2);
                ans *= 2; 
                ans %= MOD;
            }
        }

        // now we replace the question marks
        if(c == 1) {
            cout << "-1\n";
            continue;
        }
    
        int pow = 1e9;
        for(int i = 1; i < 30; ++i){
            if (c == (1<<i)){
                pow = i; break;
            }
        }
        
        for(int i = n-2; i >= 1; --i) {
            if(s[i] == '?') {
                if(i == 1) ans *= 1;
                else if(pow == 1) ans *= i;
                else {
                    ans *= 2; --pow;
                }
                ans %= MOD;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}