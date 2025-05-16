/*
1155E
*/
    
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
    
using namespace std; 
    
using ll = long long; 
    
ll mod = 1e6+3; 
    
ll binexp(ll a, ll e){
    ll cur = 1; 
    ll pow = a; 
    for(int i = 0; i < 21; ++i){
        if(e & (1ll << i)) cur = cur*pow % mod; 
        pow = pow*pow%mod; 
    }
    return cur; 
}
    
ll inv(ll a) {return binexp(a, mod-2); }
    
int main(){
    
    vector<long long> pts(12); 
    
    
    for(int i = 0; i <= 11; ++i){
        cout << "? " << i << endl; 
        cin >> pts[i]; 
        if(pts[i]  == 0){
            cout << "! " << i << endl; 
            return 0;
        }
    }
    
    // can now construct lagrange polys
    vector<long long> fac(mod, 1), invfac(mod, 1); 
    vector<long long> invs(mod, 0); 
    for(int i = 1; i < mod; ++i) invs[i] = inv(i);  //precompute invs
    
    for(int i = 1; i < mod; ++i){
        fac[i] = 1ll*i*fac[i-1]%mod; 
        invfac[i] = invs[fac[i]];
    }
    
    // computes the i-th lagrange poly at x (points (1, y1), ... , (11, y11))
    // x >= 12
    function<long long(int, int)> fi = [&](int i, int x){
        //denom is (i-1)...(i-(i-1)) (i-(i+1) .. i-11)
        // = (-1)^{11 - i} * (11-i)! * (i-1)! 
        ll denom = fac[11-i] * fac[i-1] % mod;
        if((11-i)%2) denom = mod - denom;
    
        ll num = fac[x - 1] *invfac[x-12] * invs[x-i]%mod; 
        num = num * pts[i] % mod; 
        //cout << i << " " << x << " " << num << " " << denom << "\n"; 
        return num * invs[denom] % mod; 
    };
    
    for(int i = 12; i < mod; ++i){
        ll fx = 0; 
        for(int j = 1; j<=11; ++j){
            fx = (fx+fi(j, i))%mod; 
        }
        //cout << fx << "\n"; 
        if(fx == 0){
            cout << "! " << i << endl; 
            return 0;
        }
    }
    
    cout << "! -1" << "\n"; 
    
    return 0;
}