/*
cses1712
*/

#include <iostream>

using namespace std; 

long long binexp(long long a, long long e, long long MOD){
    long long ans = 1, pow = a; 
    for(int i = 0; i < 60; ++i){
        if(e & (1LL << i)) ans *= pow; 
        pow *= pow; 
        ans %= MOD; 
        pow %= MOD;  
    }
    return ans; 
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int t; cin >> t; 
    while(t--){
        long long a, b, c; cin >> a >> b >> c; 
        long long bc = binexp(b, c, 1e9+6); 
        cout << binexp(a, bc, 1e9+7) << "\n"; 
    }
    return 0;
}