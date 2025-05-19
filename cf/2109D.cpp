/*
2109A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set> 
#include <map> 
#include <functional>
#include <queue>

using namespace std; 

long long IMPOSSIBLE = 1e15+1;
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    long long t; cin >> t; 
    while(t--){
        long long n, m, l; cin >> n >> m >> l; 
        vector<vector<long long>> g(n+1); 
        

        long long smallOdd = 1e9+1;
        long long total = 0; // max 2e9 fits in int?
        for(long long i = 0; i < l; ++i){
            long long al; cin >> al; 
            if(al % 2) smallOdd = min(smallOdd, al); 
            total += al; 
        }
        long long maxEven = -1, maxOdd = -1; 
        if(total % 2) maxOdd = total; 
        else{
            if(smallOdd != 1e9+1) maxOdd = total - smallOdd;
        }

        if(total % 2 == 0) maxEven = total; 
        else if(smallOdd != 1e9+1) maxEven = total - smallOdd;

        for(long long i = 0; i < m; ++i){
            long long u, v; cin >> u >> v; 
            g[u].push_back(v); 
            g[v].push_back(u); 
        }
        vector<long long> oddDist(n+1, IMPOSSIBLE), evenDist(n+1, IMPOSSIBLE); 
        evenDist[1] = 0; 
        queue<long long> bfs; 
        bfs.push(1); 
        while(!bfs.empty()){
            long long u = bfs.front(); bfs.pop(); 

            long long newOddDist = (evenDist[u] != IMPOSSIBLE) ? evenDist[u] + 1 : IMPOSSIBLE; 
            long long newEvenDist = (oddDist[u] != IMPOSSIBLE) ? oddDist[u] + 1 : IMPOSSIBLE; 
            for(auto v : g[u]){
                if(newOddDist != IMPOSSIBLE && oddDist[v] == IMPOSSIBLE){
                    oddDist[v] = newOddDist; 
                    bfs.push(v); 
                }
                if(newEvenDist != IMPOSSIBLE && evenDist[v] == IMPOSSIBLE){
                    evenDist[v] = newEvenDist; 
                    bfs.push(v); 
                }
            }
        }
        for(long long i = 1; i <= n; ++i){
            //cout << i << " " << evenDist[i] << " " << oddDist[i] << "\n";
            if(maxEven >= evenDist[i] || maxOdd >= oddDist[i]) cout << 1; 
            else cout <<0; 
        }
        cout << "\n";
    }
    return 0;
}