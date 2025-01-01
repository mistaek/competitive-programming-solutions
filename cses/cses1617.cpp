/*
1617
*/

#include <iostream>

using namespace std; 

long long solve(long long n){
    long long MOD = 1e9+7;
    long long ans = 1, pow = 2; 
    for(int i = 0; i < 20; ++i){
        if(n & (1LL << i)){
            ans *= pow; 
            ans %= MOD; 
        }

        pow *= pow; 
        pow %= MOD; 
    }
    return ans;
}
int main(){
    int n; cin >> n; 
    cout << solve(n) << "\n";
    return 0;
}