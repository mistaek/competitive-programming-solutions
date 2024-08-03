/*
1842D
AC
*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std; 

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m; 
    vector<vector<pair<long long, long long>>> g(n+1); 
    vector<long long> maxstay(n+1, -1);
    vector<int> in(n+1, 1);
    in[n] = 0;

    for(int i = 0; i < m; i++){
        long long u, v, y; cin >> u >> v >> y; 
        g[v].push_back({u, y});
        if(v == n){
            if(maxstay[u] == -1) maxstay[u] = y; 
            else maxstay[u] = min(maxstay[u], y); 
        }
        else g[u].push_back({v, y}); 
    }
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> nxtout; 
    for(int i = 1; i <= n; i++){
        if(maxstay[i] != -1){
            nxtout.push({maxstay[i],i});
        }
    }
    long long inf = 0, curt = 0;
    vector<pair<vector<int>, long long>> output; 
    for(int game = 0; game < n*n; ++game){
        if(in[1] == 0) break; // done
        if(nxtout.empty()){
            inf = 1; 
            break; 
        }
        auto a = nxtout.top(); nxtout.pop();
        //cout << a.second << "\n";
        if(!in[a.second]) continue; 
        if(a.first > curt){
            output.push_back({in, a.first - curt});
            curt = a.first; 
        }
        //remove a.second
        in[a.second] = 0;
        for(auto v : g[a.second]){
            if(in[v.first]){
                if(maxstay[v.first] == -1 || curt + v.second < maxstay[v.first]){
                    maxstay[v.first] = curt + v.second; 
                    nxtout.push({curt+v.second, v.first});
                }
            }
        }
    }

    if(inf) cout << "inf\n"; 
    else{
        cout << curt << " " << output.size() << "\n";
        for(auto p : output){
            for(int i = 1; i <= n; i++) cout << p.first[i]; 
            cout << " " << p.second << "\n";
        }
    }
    

    return 0;
}