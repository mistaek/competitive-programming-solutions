/*
954G
AC
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, r, k; cin >> n >> r >> k; 

    vector<long long> a(n), v(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
        v[i] = a[i];
    }
    queue<pair<long long, long long>> mod; 
    long long curm = 0; 
    for(int i = 0; i < n; ++i){
        while(!mod.empty() && mod.front().first < i){
            curm -=mod.front().second;
            mod.pop();
        }
        mod.push({i + r, a[i]});
        v[i] += curm;  
        curm += a[i];
    }

    /*
    for(int i = 0; i < n; ++i){
        cout << v[i] << " "; 
    }
    cout << "\n";
    //*/

    mod = queue<pair<long long, long long>>();
    curm = 0;
    for(int i = n-1; i >= 0; --i){
        while(!mod.empty() && mod.front().first > i){
            curm -= mod.front().second;
            mod.pop();
        }
        mod.push({i-r, a[i]});
        v[i] += curm; 
        curm += a[i];
    }
    /*
    for(int i = 0; i < n; ++i){
        cout << v[i] << " "; 
    }
    cout << "\n";
    //*/
    long long hi = 2e18, lo = 0; 
    while(lo < hi){
        mod = queue<pair<long long, long long>>();
        curm = 0;
        long long mid = (lo + hi+1)/2; 
        //check if mid is doable:
        long long req = 0;
        for(int i = 0; i < n; ++i){
            while(!mod.empty() && mod.front().first < i){
                curm -= mod.front().second;
                mod.pop();
            }
            if(v[i] + curm < mid){
                mod.push({i + 2*r, mid - (v[i] + curm)});
                req += mid- (v[i] + curm); 
                curm += mid - (v[i] + curm);
            }
            if(req > k) break; 
        }
        if(req > k){
            hi = mid-1; 
        }
        else lo = mid; 
    }

    cout << lo << "\n";
    return 0;
}