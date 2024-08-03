/*
1841E
*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        using lli = long long;
        lli n, m;
        cin >> n; 
        vector<lli> curh(n);
        priority_queue<pair<lli, lli>> shrink, rects;
        set<pair<lli, lli>> intv; 
        for(lli i = 0; i<n; ++i){
            lli h; cin >> h;
            shrink.push({h, i});
        }

        intv.insert({0, n-1});
        curh[0] = n; 
        while(!shrink.empty()){
            auto [h, i] = shrink.top(); 
            shrink.pop();

            auto p = intv.lower_bound({i,i});
            if(p == intv.end() || p->first > i) p = prev(p); //should not error(?) 
            if(curh[p->first] - h){
                rects.push({p->second - p->first + 1, curh[p->first] - h});
            }
            auto l = p->first, r = p->second; 
            intv.erase(p);
            if(l < i){
                intv.insert({l, i-1});
                curh[l] = h; 
            }
            if(r > i){
                intv.insert({i+1, r});
                curh[i+1] = h; 
            }
        }
        cin >> m; 
        lli ans = 0; 
        while(m){
            auto [w, h] = rects.top(); rects.pop(); 
            //cout << w << " " << h << "\n";
            if(m >= w*h){ 
                m -= w*h; 
                ans += (w-1)*h; 
            }
            else{
                lli div = m/w, mod = m % w; 
                m -= div * w;
                ans += (w-1) * div; 
                if(mod) ans += mod - 1; 
                m -= mod; 
            }
        }
        cout << ans << "\n";
        
    }
    return 0;
}