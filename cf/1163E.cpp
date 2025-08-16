/*
1163E
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int n; cin >> n; 
    vector<int> a(n), b, bb; 
    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
    }

    sort(a.begin(), a.end()); 

    auto add = [&](int ai){
        int tmp = ai; 
        for(auto bi : b) ai = min(ai, ai ^ bi); 
        if(ai){ b.push_back(ai); bb.push_back(tmp); }
    };

    int curi = 0, best = 0; 
    for(auto ai : a){
        while(ai >= (1 << curi)){
            if(b.size() == curi) best = curi; 
            ++curi; 
        }
        add(ai); 
    }
    if(b.size() == curi) best = curi; 
    /*for(auto bi : b) cout << bi << " "; 
    cout << "\n"; */


    if(best == 0){
        cout << "0\n0\n"; 
    }
    else{
        cout << best << "\n"; 
        vector<bool> vis((1 << best), 0); 
        auto dfs = [&](const auto& s, int u)->void{
            vis[u] = true; 
            cout << u << " "; 
            for(int i = 0; i < best; ++i){
                if(!vis[u ^ bb[i]]){
                    s(s, u^bb[i]);
                    return; 
                }
            }
        };
        dfs(dfs,0); 
        cout << "\n"; 
    }

    return 0;
}