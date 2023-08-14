/*
1829H
AC
*/

#include <iostream>
#include <algorithm>
long long MOD = 1e9+7;
long long cnt[64] ={};
long long a[64] = {};
using namespace std; 

int countBits(int n){
    int ans = 0; 
    for(int i = 0; i < 6; i++){
        if(n & (1 << i)) ans++; 
    }
    return ans; 
}

long long modIt(long long n){
    n %= MOD;
    while(n < 0) n += MOD;
    return n;
}

long long pow2(long long exp){
    long long ans = 1, pow = 2; 
    for(int i = 0; i < 32; i++){
        if(exp & (1 << i)){
            ans *= pow; 
            ans = modIt(ans);
        }
        pow *= pow; 
        pow = modIt(pow);
    }
    return ans % MOD;
}

long long getAns(int t){
    if(t >=64) return 0;
    if(a[t] != -1) return a[t];
    
    long long ans = 0;
    for(int i = t; i < 64; i++){
        if((i & t) < t) continue; 
        if(cnt[i]){
            if(ans == 0){
                ans = pow2(cnt[i]);
                ans = modIt(ans);
            }
            else{
                ans *= pow2(cnt[i]); 
                ans = modIt(ans);
            }
        }
    }
    if(ans) ans--;
    ans = modIt(ans);
    for(int i = t+1; i < 64; i++){
        if((i & t) == t){
            ans -= getAns(i); 
            ans = modIt(ans);
        }
    }
    
    //if(ans) cout << t << " " << ans << "\n";
    ans = modIt(ans);
    return a[t] = ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        for(int i = 0; i < 64; i++){ cnt[i] = 0; a[i] = -1;}
        long long n, k; cin >> n >> k; 
        long long ans = 0;
        for(int i = 0; i < n; i++){
            int a; cin >> a; 
            cnt[a]++;
        }
        for(int tgt = 0; tgt < 64; tgt++){
            if(countBits(tgt) != k) continue; 

            ans += getAns(tgt);
            
            ans = modIt(ans);
        }
        
        cout << ans << "\n";
    }
    return 0;
}