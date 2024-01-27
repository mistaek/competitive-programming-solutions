/*
1899G
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 


vector<int> s, f, a;
vector<vector<int>> g, st; 
int t = 0;

void dfs(int u){
    s[u] = t++; 
    for(auto v : g[u]){
        if(s[v] == -1) dfs(v); 
    }
    f[u] = t++;
}

void build(int i, int l, int r){
    if(l == r){
        st[i].push_back(a[l]);
        return; 
    }
    int mid = (l+r)/2; 
    build(i+1, l, mid); 
    build(i + 2*(mid - l + 1), mid+1, r);
    merge(st[i+1].begin(), st[i+1].end(), st[i + 2*(mid - l + 1)].begin(), st[i + 2*(mid - l + 1)].end(), back_inserter(st[i]));
}

bool check(int i, int v){
    auto it = lower_bound(st[i].begin(), st[i].end(), s[v]);
    return ((it != st[i].end()) && *it < f[v]); 
}
bool query(int i, int ql, int qr, int l, int r, int v){
    if(ql == l && qr == r){
        return check(i, v);
    }

    int mid = (l+r)/2; 
    if(qr <= mid) return query(i+1, ql, qr, l, mid, v);
    else if(ql > mid) return query(i + 2*(mid - l + 1), ql, qr, mid+1, r, v);
    else{
        return (query(i+1, ql, mid, l, mid, v) || query(i+ 2 * (mid - l + 1), mid+1, qr, mid+1, r, v));
    }
}

int main(){
    int tc; cin >> tc; 
    while(tc--){
        int n, q; cin >> n >> q; 
        t = 0; 
        a = vector<int>(n);
        s = vector<int>(n, -1), f = vector<int>(n, -1);
        g = vector<vector<int>> (n), st = vector<vector<int>>(2*n); 
        for(int i = 0; i < n-1; i++){
            int u, v; cin >> u >> v; 
            g[--u].push_back(--v); g[v].push_back(u); 
        }

        dfs(0);
        for(int i = 0; i < n; i++){
            int pi; cin >> pi; 
            a[i] = s[--pi];
        }
        
        build(0, 0, n-1);
        for(int i = 0; i < q; i++){
            int l, r, x; cin >> l >> r >> x; 
            cout << (query(0, --l, --r, 0, n-1, --x) ? "YES" : "NO") << "\n";
        }
        cout << "\n";
    }
    return 0;
}