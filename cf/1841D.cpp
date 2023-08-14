/*
1841D
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

bool sorter(pair<int, int> a, pair<int, int> b){
    return (a.second < b.second);
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        pair<int, int> ivl[n];
        for(int i = 0; i < n; i++){
            cin >> ivl[i].first >> ivl[i].second;
        }
        
        vector<pair<int, int>> intersect;
        for(int i = 0; i < n; i++){
            bool paired = false; 
            for(int j = i+1; j < n; j++){
                if((ivl[j].first <= ivl[i].first && ivl[j].second >= ivl[i].first) || (ivl[j].first <= ivl[i].second && ivl[j].second >= ivl[i].second) || (ivl[i].first <= ivl[j].first && ivl[i].second >= ivl[j].first) || (ivl[i].first <= ivl[j].second && ivl[i].second >= ivl[j].second)){
                    intersect.push_back({min(ivl[i].first, ivl[j].first), max(ivl[i].second, ivl[j].second)});
                }
            }
        }
        sort(intersect.begin(), intersect.end(), sorter);
        int chosen = 0; 
        int lfin = -1; 
        for(int i = 0; i < intersect.size(); i++){
            if(intersect[i].first > lfin){
                chosen++; 
                lfin = intersect[i].second;
            }
        } 
        
        cout << n - 2*chosen << "\n"; 
    }
    return 0;
}