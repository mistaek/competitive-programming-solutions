/*
1821D
ac :)
*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        vector<pair<long long, long long>> seg(n); 
        multiset<long long> active; 
        for(int i = 0; i < n; ++i){
            cin >> seg[i].first; 
        }
        for(int i = 0; i < n; ++i){
            cin >> seg[i].second;
        }

        long long ans = 1e15, tc = 0, curp = 0;  
        for(int i = 0; i < n; ++i){
            curp = seg[i].first; 
            tc += 1; 
            if(tc < k){
                curp += min(seg[i].second - seg[i].first, k - tc); 
                tc += min(seg[i].second - seg[i].first, k - tc);
            }
            if(tc >= k){
                ans = min(ans, static_cast<long long>(curp + 2 + 2*active.size()));
                //cout << "Possible " << curp << " " << ans << " " << active.size() << "\n"; 
                auto it = active.begin();
                while(it != active.end()){
                    //cout << "consider remove " << *it << "\n";
                    if(tc - *it + seg[i].second - curp>=k){
                        ans = min(ans, static_cast<long long>(curp + 2 + 2*active.size())); 
                        //cout << "Possible " << curp << " " << ans << "\n"; 

                        tc -= *it; 
                        it = active.erase(it); 
                        curp += max(0LL, k - tc);
                        tc += max(0LL, k-tc);
                        ans = min(ans, static_cast<long long>(curp + 2 + 2*active.size())); 
                        //cout << "Possible " << curp << " " << ans << "\n"; 

                    }
                    else{
                        break; 
                    }
                }
            }
            tc += seg[i].second - curp; 
            active.insert(seg[i].second - seg[i].first + 1);
        }

        if(ans == 1e15){
            cout << -1 << "\n"; 
        }
        else cout << ans << "\n";
        


                
    }
    return 0;
}