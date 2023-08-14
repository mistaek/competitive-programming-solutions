/*
1839A
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

bool psort(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first) return true;
    if(a.first > b.first) return false; 
    return (a.second > b.second); 
}
pair<int, int> lamps[200001];
int brk[200001] = {};
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        long long ans = 0, on = 0, maxon = 0; 
        
        for(int i = 0; i < n; i++){
            brk[i] = 0;
            cin >> lamps[i].first >> lamps[i].second;
            //cout << lamps[i].first << " " << lamps[i].second << "\n";

        }
        sort(lamps, lamps+n, psort);
        for(int i = 0; i < n; i++){
            //cout << lamps[i].first << " " << lamps[i].second << "\n";
            if(lamps[i].first <= maxon) continue; 
            ans += lamps[i].second;
            brk[lamps[i].first]++;
            on++;
            maxon = max(on, maxon);
            if(on == maxon){
                on -= brk[on];
                brk[maxon] = 0;
            }
            //cout << on << "\n";
            
        }
        cout << ans << "\n";
    }
    return 0;
}