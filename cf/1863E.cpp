/*
1863E
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        long long n, m, k; 
        cin >> n >> m >> k; 

        vector<long long> h(n+1, 0), indeg(n+1, 0), outdeg(n+1, 0), s(n+1, 0);
        for(int i = 1; i <= n; i++) cin >> h[i]; 

        vector<vector<long long>> g(n+1), rg(n+1);
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b; 
            g[a].push_back(b); 
            rg[b].push_back(a);
            ++indeg[b]; 
            ++outdeg[a];
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq; 
        for(int i = 1; i <= n; i++){
            if(indeg[i] == 0){
                pq.push({h[i], i});
            }
        }
        while(!pq.empty()){
            auto [t, u] = pq.top();
            s[u] = t; 
            pq.pop(); 
            long long d = t/k; t %= k; 
            for(auto v : g[u]){
                --indeg[v]; 
                if(indeg[v] == 0){
                    pair<long long, long long> pll = {h[v], v}; 
                    if(h[v] >= t){
                        pll.first += d * k; 
                    }
                    else pll.first += (d+1) * k; 
                    pq.push(pll); 
                }
            }
        }

        vector<pair<long long, long long>> sf; 
        long long end = 0;
        for(int i = 1; i<= n; i++){
            end = max(end, s[i]);
            if(rg[i].size() == 0){
                sf.push_back({s[i], i});
            }
        }
        sort(sf.begin(), sf.end());
        long long ans = end - sf[0].first; 

        for(int i = 0; i < sf.size() - 1; i++){
            sf[i].first += k; 
            s[sf[i].second] = sf[i].first; 
            pq.push(sf[i]);
            while(!pq.empty()){
                auto [t, u] = pq.top(); pq.pop();
                end = max(end, t); 
                for(auto v : g[u]){
                    //cout << v << " " << s[v]  << " " << s[u] << "\n";

                    if(s[v] < s[u]){
                        s[v] += k; 
                        pq.push({s[v], v});
                    }
                }
            }
            //cout << "Push " << sf[i].second << " " << sf[i].first << " " << end << "\n"; 
            ans = min(ans, end - sf[i+1].first);
        }
        cout << ans << "\n";
        
    }
    return 0;
}