/*
2102E
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std; 

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0); 
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> a(n); 
        multiset<int, greater<int>> pq; 
        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
            pq.insert(a[i]); 
        }

        //get max number of intervals
        set<int, greater<int>> untaken; 
        for(int i = 1; i <= n/2; ++i){
            untaken.insert(i); 
        }

        int best = 0;
        while(!pq.empty()){
            if(pq.size() == 1) break; 
            int p = *pq.begin(); pq.erase(pq.begin()); 
            int q = *pq.begin(); pq.erase(pq.begin()); 
            int opt = min(p, q); 
            if(untaken.lower_bound(opt) != untaken.end()){
                untaken.erase(untaken.lower_bound(opt)); 
                ++best; 
            }
            else break; 
        }

        long long ans = 0;
        while(best){
            untaken.clear();
            for(int i = 1; i <= best; ++i){
                untaken.insert(i); 
            }
            long long trialAns = 0;
            set<pair<int, int>, greater<pair<int, int>>> front, back; 
            for(int i = 0; i < n; ++i){
                if(untaken.lower_bound(a[i]) != untaken.end()){
                    untaken.erase(untaken.lower_bound(a[i])); 
                    front.insert({a[i], i}); 
                } 
                if((int)front.size() == best) break; 
            }

            untaken.clear(); 
            for(int i = 1; i <= best; ++i){
                untaken.insert(i); 
            }
            for(int i = n-1; i >= 0; --i){
                if(untaken.lower_bound(a[i]) != untaken.end()){
                    untaken.erase(untaken.lower_bound(a[i])); 
                    back.insert({a[i], i}); 
                } 
                if((int)back.size() == best) break; 
            }

            while(!front.empty()){
                auto p1 = *front.begin(); 
                front.erase(front.begin()); 
                auto p2 = *back.begin(); 
                back.erase(*back.begin()); 
                trialAns += p2.second - p1.second;
            }

            if(trialAns <= ans) break; 
            else{
                ans = trialAns; 
                best--;
            }

        }

        cout << ans << "\n";
    }
    
    return 0;
}