/*
1142B
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
using namespace std; 

vector<int> st, g; 

void build(int i, int l, int r){
    if(l == r) st[i] = g[l]; 
    else{
        int m = (l+r)/2; 
        build(i+1, l, m); 
        build(i+2*(m - l + 1), m+1, r); 
        st[i] = min(st[i+1], st[i+2*(m-l+1)]); 
    }
}

int query(int i, int l, int r, int ql, int qr){
    if(ql > qr) return __INT_MAX__; 
    if(ql == l && qr == r) return st[i]; 
    else{
        int m = (l+r)/2; 
        return min(query(i+1, l, m, ql, min(qr, m)), query(i+2*(m - l + 1), m+1, r, max(ql, m+1), qr));
    }
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int n, m, q; 
    cin >> n >> m >> q; 
    vector<int> p(n), invp(n); 
    vector<int> a(m);
    g = vector<int>(m+3, m+1); 
    for(int i = 0; i < n; ++i){
        cin >> p[i]; 
        --p[i]; invp[p[i]] = i; 
    }
    for(int i = 0; i < m; ++i){
        cin >> a[i]; --a[i];
    }
    

    // for each i, want a pointer to next element in the perm

    vector<queue<int>> waitin(n); 
    for(int i = 0; i < m; ++i){
        int pnext = p[(invp[a[i]] + 1) % n]; 
        waitin[pnext].push(i); 
        while(!waitin[a[i]].empty()){
            auto u = waitin[a[i]].front(); 
            waitin[a[i]].pop(); 
            g[u] = i; 
        }
    }
    //binary lifting array
    const int LOG =20; 
    vector<vector<int>> nxt(m+3, vector<int>(LOG, m+1));
    for(int i = 0; i< m; ++i){
        nxt[i][0] = g[i];
    }
    // since circular, don't need to worry about -1s tbh
    for(int k = 1; k < LOG; ++k){
        for(int i = 0; i < m; ++i){
            nxt[i][k] = nxt[nxt[i][k-1]][k-1]; 
        }
    }
    // now make g the min index array
    for(int i = 0; i < m; ++i){
        int cur = i;
        for(int k = LOG -1; k >= 0; --k){
            if((1 << k) & n-1){
                cur = nxt[cur][k];  
            }
        }
        g[i] = cur; 
    }
    st = vector<int>(2*m); 
    build(0, 0, m-1);
    for(int i = 0; i < q; ++i){
        int l, r; cin >> l >> r; 
        --l; --r; 
        if(query(0, 0, m-1, l, r) <= r){
            cout << "1"; 
        }
        else cout << "0"; 
    }
    cout << "\n";
    return 0;
}