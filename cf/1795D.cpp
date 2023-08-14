/*
1795D
*/

#include <iostream>
#include <algorithm>

using namespace std; 

long long mod = 998244353;

long long inv(long long x){
    long long ans = 1; 
    long long y = mod-2; 
    while(y){
        if(y % 2 == 1) ans*= x; 
        ans %= mod; 
        x *= x; 
        x %= mod; 
        y/=2; 
    }
    return ans; 
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    long long ans = 1;

    int n; cin >> n; 
    for(int i = 1; i <= (n/6); i++){
        ans *= (n/6) + i;
        ans %= mod;
        ans *= inv(i);
        ans %= mod; 
    }

    
    for(int i = 0; i < (n/3); i++){
        int e1, e2, e3; 
        cin >> e1 >> e2 >> e3; 
        
        int a[3] = {e1, e2, e3}; 
        sort(a, a+3); 
        int m = 0; 
        for(int j = 0; j < 3; j++){
            if(a[j] == a[0]) m++;
        }
        ans*= m;
        ans %= mod; 
    }
    
    cout << ans << "\n";
    
    
    return 0;
}