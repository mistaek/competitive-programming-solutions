/*
919E
AC, i'm dumb
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

long long p; 
long long binexp(long long b, long long exp){
    long long ans = 1, curpow = b;
    for(int i = 0; i < 62; ++i){
        if(exp & (1LL << i)) ans *= curpow; 
        ans %= p; 
        curpow *= curpow;
        curpow %= p; 
    }

    return ans; 
}
long long inv(long long n){
    return binexp(n, p-2);
}
int main(){
    long long a, b, x; cin >> a >> b >> p >> x; 
    if(a == 1){
        cout << (x/p) + (b <= x % p) << "\n";
        return 0;
    }

    vector<long long> exp(p+1);
    long long ord = p-1;
    long long cur = a;
    for(int i = 1; i<= p-1; ++i){
        //cout << cur << " " << i << "\n";
        exp[cur] = i; 
        cur *= a; cur %= p;
        if(cur == a){ ord = i; break; }
    }
    //cout << ord << "\n";

    long long ans = 0;
    for(long long i = 1; i <= min(x, p-1); ++i){
        long long occ = (x/p) + (i <= (x % p));
        long long rhs = (b * inv(i)) % p;
        if(exp[rhs] == 0) { continue;  }
        long long turn = (exp[rhs] - i + 1);
        while(turn <= 0) turn = ord +turn; 
        //cout << i << " " << occ << " " << turn << " " << (occ/ord) + (turn <= occ %ord) << "\n";
        ans += (occ/ord) + (turn <= occ %ord);
    }

    cout << ans << "\n";
    return 0;
}