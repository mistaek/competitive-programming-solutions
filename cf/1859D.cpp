/*
1859D
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<pair<int, int>> intvs;
        
        for(int i = 0; i < n; i++){
            int a, l, b, r; //we ignore l r
            cin >> l >> r >> a >> b; 
            intvs.push_back({l, b});
        }
        sort(intvs.begin(), intvs.end());

        //merge
        vector<pair<int, int>> escape; 
        pair<int, int> cur = intvs[0]; 
        for(int i = 0; i < n; i++){
            if(intvs[i].first > cur.second){
                //end of the line
                escape.push_back(cur); 
                //cout << cur.first << " " << cur.second << "\n";
                cur = intvs[i]; 
            }
            else{
                cur.second = max(cur.second, intvs[i].second);
            }
        }
        escape.push_back(cur); 
        //cout << cur.first << " " << cur.second << "\n";

        int q; cin >> q; 
        for(int i = 0; i < q; i++){
            if(i) cout << " "; 
            int x; cin >> x; 
            auto it = lower_bound(escape.begin(), escape.end(), make_pair(x, 0));
            if(it == escape.end()){
                it--;
                cout << max(x, it->second); //nothing compares greater
            }
            else{
                if(x == it->first) cout << it->second ;
                else if(it == escape.begin()) cout << x ; 
                else{
                    it--; 
                    cout << max(x, it->second);
                }
            }
        }
        cout << "\n";


    }
    return 0;
}