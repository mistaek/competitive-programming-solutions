/*
963A
*/

#include <iostream>
#include <vector>

using namespace std; 

long long MOD = 1e9+9;

long long mod(long long n){
    n %= MOD; 
    while(n <0) n+= MOD; 
    return n; 
}

long long binexp(long long base, long long exp)
{
    long long ret = 1;

    long long pow = base; 
    for(int i = 0; i < 32; ++i){
        if(exp & (1 << i))
        {
            ret *= pow;
            ret = mod(ret);
            if(ret > MOD) cout << "?";
        }
        pow *= pow; 
        pow = mod(pow);
    }

    return ret;
}

long long inv(long long n)
{
    return binexp(n, MOD-2);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<long long> s(k, 0);
    for(int i = 0; i < k; ++i){
        char c; 
        cin >> c; 
        if(c == '+') s[i] = 1; 
        else s[i] = -1; 
    }

    long long ratio = b * inv(a);
    ratio = mod(ratio);

    long long numerator = binexp(ratio, n+1);
    numerator = 1- numerator; 
    numerator = mod(numerator);

    long long denom = binexp(ratio, k); 
    denom = 1 - denom; 
    denom = mod(denom);

    denom = inv(denom);

    long long frac = mod(numerator * denom);
    long long ans = 0;
    long long cur = binexp(a, n);
    for(int i = 0; i < k; ++i){
        long long sum = mod(cur * frac);
        if(frac == 0) sum = mod(cur * (n+1)/k);  // this is when ratio is 1
        sum *= s[i]; 
        sum = mod(sum);
        ans = mod(ans + sum);
        cur = mod(cur * ratio);
    }

    cout << ans << "\n";
    return 0;
}