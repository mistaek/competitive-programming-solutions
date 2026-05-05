/*
2225C
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long long MOD = 998244353;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        long long n, x; cin >> n >> x;
        long long numStartZero = x/4;
        long long numStartOne = x/2 - x/4;
        numStartOne %= MOD;
        numStartZero %= MOD;

        long long xM0 = x - (x % 4) + 3, nM0 = n - (n%4) + 3;
        long long numEndZero;
        if(xM0 < x) xM0 += 4;
        if(nM0 > n) nM0 -=4;
        if(nM0 < xM0) numEndZero = 0;
        else {
            numEndZero = (nM0 - xM0)/4 + 1;
        }
        numEndZero %= MOD;

        long long numEndOne;
        long long xM2 = x - (x%4) + 1, nM2 = n - (n % 4) + 1; 
        if (xM2 < x) xM2 += 4; 
        if (nM2 > n) nM2 -= 4;
        if (nM2 < xM2) numEndOne = 0;
        else numEndOne = (nM2 - xM2)/4 + 1;
        numEndOne %= MOD;

        //cout << numStartZero << " " << numStartOne << " " << numEndZero << " " << numEndOne << " " << (nM0-xM0) << "\n";
        long long ans = (numStartZero * numEndZero % MOD);
        ans += numEndZero;
        ans %= MOD;
        ans += (numStartOne * numEndOne % MOD);
        ans %= MOD;
        cout << ans << "\n";

    }
    return 0;
}