/*
1891D
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

long long MOD = 1e9+7; 
long long inf = 1e18;

long long nvlog(long long a, long long b){
    //naive log since answers should be pretty small
    long long ans = 0, pow = b; 
    while(pow <= a){
        ans++;
        if(inf / b > pow) pow *= b; 
        else return ans; 
    }
    return ans; 
}

long long nvpow(long long a, long long b){
    //no binexp needed i think
    long long ans = 1;
    for(int i = 0; i < b; i++){
        if(inf/a > ans) ans *= a; 
        else return inf +1; 
    }
    return ans; 
}

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);

    vector<pair<long long, long long>> iv; // intv start, num  
 
    for(int i = 2; i <= 60; i++){
        long long z = nvlog((1LL << i), i);
        iv.push_back({(1LL << i), z});
        //cout << (1LL << i) << " " << z << "\n";
        if(i == 60) break;         
        long long j = nvpow(i, z+1); 
        if(j < (1LL<<(i+1))){
            iv.push_back({j, z+1}); 
            //cout << j << " " << z+1 << "\n";
        }

    }
    
    int q; cin >> q; 
    while(q--){
        long long l, r; cin >> l >> r; 
        long long ans = 0; 
        for(int i = 0; i < iv.size() - 1; i++){
            if(iv[i].first > r) break; 
            if(iv[i].first < l && iv[i+1].first >l){
                long long diff = min(r+1, iv[i+1].first) - l; 
                diff %= MOD; 
                diff *= iv[i].second; 
                diff %= MOD;
                ans += diff; 
                ans %= MOD; 
            }
            if(iv[i].first >= l){
                long long diff = min(r+1, iv[i+1].first) - iv[i].first; //num of nums
                diff %= MOD; 
                diff *= iv[i].second; 
                diff %= MOD;
                ans += diff; 
                ans %= MOD; 
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}