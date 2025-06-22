/*
2120C
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        long long m, n; cin >> n >> m; 
        bool attached[n+1] = {};
        vector<pair<int, int>> edges; 
        long long mx = (n * (n+1)) /2, mn = n; 

        if(mx < m || mn > m){
            cout << "-1\n"; 
            continue; 
        }
        long long curRoot = n; 
        while(mx - curRoot + 1 >= m){
            if(curRoot == 1) break; 

            mx -= curRoot - 1; 
            edges.push_back({1, curRoot}); 
            attached[curRoot] = true; 
            curRoot = curRoot - 1;
        }

        long long diff = mx - m;
        if(diff != 0){
            // diff is at most curRoot - 2, or e    lse we would move curRoot 
            edges.push_back({1, diff+1}); 
            attached[diff+1] = true; 
        }

        for(int i = 1; i <= n; ++i){
            if(i != curRoot && !attached[i]) edges.push_back({i, curRoot}); 
        }

        cout << curRoot << "\n"; 
        for(auto p : edges){
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}