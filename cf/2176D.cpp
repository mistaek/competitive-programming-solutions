/*
2176D
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

long long MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<pair<long long, long long>> a(n);
        vector<long long> vals(n+1);
        for(int i = 0; i < n; ++i) {
            cin >> a[i].first; 
            a[i].second = i+1;
            vals[i+1] = a[i].first;
        }
        sort(a.begin(), a.end(), greater<pair<long long, long long>>());
        vector<map<long long, long long>> ms(n+1);

        vector<vector<long long>> g(n+1);
        for(int i = 0; i < m; ++i){ 
            int u, v; cin >> u >> v; g[v].push_back(u);
        }

        long long ans = 0;
        for(int i = 0; i < n; ++i){
            int u = a[i].second; // current vertex
            //cout << "Considering vertex " << a[i].second << " with value " << a[i].first << "\n";
            for(auto v : g[u]) {
                long long vl = vals[v], ul = a[i].first;
                long long outgoing = 1 + ms[u][ul + vl];
                outgoing %= MOD;
                /*
                cout << "     Trying to go from " << ul << " to " << vl << "\n";
                cout << "     Found " << outgoing << " generalized fibonacci sequences starting at " << vl << " and passing through " << ul + vl << "\n";
                cout << "     Set " << v << " " << u << " to " << outgoing << "\n";
                cout << "\n";
                */
                ms[v][ul] += outgoing;
                ms[v][ul] %= MOD;
                ans += outgoing;
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}