/*
1882D
AC
*/

#include <iostream>
#include <vector>

using namespace std; 


long long idfs(int idx, int p, vector<long long> &a, vector<vector<int>> &g, vector<long long> &c, vector<long long> &s){
    c[idx] = a[idx] ^ a[p];
    s[idx] = 1; 
    long long ret = 0;
    for(auto v : g[idx]){
        if(v != p){
            ret += idfs(v, idx, a, g, c, s);
            s[idx] += s[v];
        }
    }
    return ret + (c[idx] * s[idx]);
}   

void adfs(int u, int p, vector<long long> &a, vector<vector<int>> &g, vector<long long> &c, vector<long long> &s, vector<long long> &ans){
    for(auto v : g[u]){
        long long su = s[u], sv= s[v], cu = c[v], cv = c[v];
        if(v!= p){
            s[u] -= s[v], c[u] = a[u] ^ a[v];
            c[v] = 0; s[v] += s[u]; 
            ans[v] = ans[u] - cv * sv;
            ans[v] += c[u] * s[u];
            adfs(v, u, a, g, c, s, ans);
        }
        s[u] = su, s[v] = sv, c[u] = cu, c[v] = cv; 
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        vector<long long> a(n); 
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<vector<int>> g(n); 
        for(int i = 0; i < n-1; i++){
            int u, v; cin >> u >> v; 
            --u, --v; 
            g[u].push_back(v); g[v].push_back(u);
        }
        vector<long long> ans(n, 0);
        vector<long long> c(n,0 ), s(n,0); //cost at subtree to xor to parent, size
        ans[0] = idfs(0, 0, a, g, c, s); 

        adfs(0, 0, a, g, c, s, ans);

        for(int i = 0; i < n; i++){
            if(i) cout << " "; 
            cout << ans[i];
        }
        cout << "\n";
    } 

    return 0;
}