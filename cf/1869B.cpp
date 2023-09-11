/*
1869A
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n, k, a, b; cin >> n >> k >> a >> b; 
        pair<long long, long long> cities[n]; 

        for(int i = 0; i < n; i++){
            cin >> cities[i].first >> cities[i].second; 
        }
        bool am=  (a <= k), bm = (b <= k); 
        
        long long sf = abs(cities[a-1].first - cities[b-1].first) +  abs(cities[a-1].second - cities[b-1].second); 
        long long ac = 1e10, bc = 1e10; 
        if(!am){
            for(int i = 0; i < k; i++){
                ac = min(ac, abs(cities[i].first - cities[a-1].first) + abs(cities[i].second - cities[a-1].second)); 
            }
        }
        else ac = 0; 
        if(!bm){
            for(int i = 0; i < k; i++){
                bc = min(bc, abs(cities[i].first - cities[b-1].first) + abs(cities[i].second - cities[b-1].second)); 
            }
        }
        else bc = 0; 
        cout << min(sf, ac + bc) << "\n"; 
    }   
    return 0;
}