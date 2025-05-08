/*
2108C
Simulation solution, not ideal
*/
    
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
    
using namespace std; 
    
int main(){
    cin.tie(0); 
    cout.tie(0); 
    ios_base::sync_with_stdio(0); 
    
    
    
    int t; cin >> t; 
    int ctr = 0;
    while(t--){
        ++ctr; 
        int n; cin >> n; 
        vector<int> weights(n); 
        set<pair<int, int>, greater<pair<int, int>>> pq, erasible; //{weight, index}
        set<int> exist; 
    
        for(int i = 0; i < n; ++i){
            cin >>weights[i]; 
            pq.insert({weights[i], i}); 
            exist.insert(i);
        }

        int ans= 0;
        for(int i = 0; i < n;){
            ++ans; 
            erasible.insert(*pq.begin()); 

            while(i < n && !erasible.empty() && erasible.begin()->first == pq.begin()->first){
                int ind = erasible.begin()->second; 

                auto it = exist.find(ind); 

                if(it == exist.end()) cout << ctr << "wot\n"; 

                pq.erase(*erasible.begin());  // erase early
                erasible.erase(erasible.begin()); 
                if(it != exist.begin()){
                    erasible.insert({weights[*prev(it)], *prev(it)}); 
                }

                if(next(it) != exist.end()){
                    erasible.insert({weights[*next(it)], *next(it)});
                }
    
                exist.erase(ind); 
                
                ++i; 
    
            } 
        }
    
        cout << ans << "\n";
    }
    return 0;
}