/*
955C
ac
wahsai
*/

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std; 

vector<int> pf(70, 0);
vector<vector<long long>> precomputed(62);

long long BREAKPOINT = 3;
long long binexp(long long base, long long exp){
    long long cur = 1; 
    long long pow = base; 
    for(long long i = 0; i < 62; ++i){
        if((1LL << i) > exp) break; 
        if(exp & (1LL << i)){
            if(numeric_limits<long long>::max() / pow <= cur){
                return numeric_limits<long long>::max();
            }
            cur *= pow; 
        }
        if(numeric_limits<long long>::max() / pow <= pow){ pow = numeric_limits<long long>:: max(); }
        else pow *= pow; 
    }
    return cur; 
}

long long solve(long long l, long long r){
    // find first int which has pow > l and < r for each exp
    long long ans = 0;

    for(long long i = 2; i < 62; ++i){
        if(i < BREAKPOINT){
            long long gl, lr;
            long long lo = 2, hi = 1e18;
            while(lo < hi){
                long long mid = (lo + hi)/2; 
                long long mexpi = binexp(mid, i);
                if(mexpi >= l) hi = mid; 
                else lo = mid+1;
            }
            gl = lo;
            lo = 2, hi = 1e18; 
            while(lo < hi){
                long long mid = (lo + hi + 1)/2; 
                long long mexpi = binexp(mid, i); 
                if(mexpi <= r) lo = mid; 
                else hi = mid-1; 
            }
            if(binexp(hi, i) > r) --hi; 
            lr = hi; 
            if(lr < gl) continue; 
            if(pf[i] == 0) ans += lr - gl + 1; 
            else if(pf[i] == 2) ans -= lr - gl + 1;
            else if(pf[i] == 3) ans += lr - gl + 1; 
           
        }
        else 
        {
            auto it1 = lower_bound(precomputed[i].begin(), precomputed[i].end(), l);
            auto it2 = upper_bound(precomputed[i].begin(), precomputed[i].end(), r);
             if(pf[i] == 0 || pf[i] == 3) ans += it2 - it1; 
            else if(pf[i] == 2) ans -= it2-it1;
        }
    }  

    // special case for 1
    if(l == 1) ans++;
    return ans; 
}

int main(){
    for(int i = 2; i < 70; ++i){
        if(pf[i] == 0){
            for(int j = 2*i; j < 70; j += i) ++pf[j]; 
        }
    }
    for(int i = 2; i < 70; ++i){
        if(pf[i] == 0){
            for(int j = i*i; j < 70; j += i * i) pf[j] = 1;
        }
    }

    // precompute powers
    for(long long i = 2; i <= 1e6; ++i){
        for(long long j = BREAKPOINT; j < 62; ++j){
            auto v = binexp(i, j);
            if(v == numeric_limits<long long>::max()) break; 
            precomputed[j].push_back(v);

        }
    }
    
    int q; cin >> q; 
    for(int i = 0; i < q; ++i){
        long long l, r; cin >> l >> r; 
        cout << solve(l, r) << "\n";
    }
    


    return 0;
}