/*
1137
*/

#include <iostream>
#include <vector>

using namespace std; 

vector<int> a, b; 
vector<long long> st; 
vector<int> startTime, endTime; 
vector<vector<int>> g; 


void dfs(int u, int prev){
    static int timer = 0;
    startTime[u] = timer++; 
    b.push_back(a[u]); 
    for(auto v : g[u]){
        if(v != prev){
            dfs(v, u); 
        }
    }

    endTime[u] = timer; 
}


void build(int i, int l, int r){
    if(l == r) st[i] = b[l];
    else{
        int mid = (l+r)/2; 
        build(i+1, l, mid); 
        build(i+2*(mid - l + 1), mid+1, r); 
        st[i] = st[i+1] + st[i+2*(mid-l+1)]; 
    } 
}

long long query(int i, int l, int r, int ql, int qr){
    if(ql > qr) return 0;
    if(ql == l && qr == r) return st[i]; 
    else{
        int mid = (l+r)/2; 
        return query(i+1, l, mid, ql, min(qr, mid)) + query(i+2*(mid - l + 1), mid+1, r, max(ql, mid+1), qr);
    }
}

void upd(int i, int l, int r, int idx, long long v){
    if(l > idx || r < idx) return; // out of range
    if(l == r){
        st[i]= v; 
    }
    else{
        int mid = (l+r)/2; 
        upd(i+1, l, mid, idx, v); upd(i+2*(mid-l+1), mid+1, r, idx, v);
        st[i] = st[i+1] + st[i+2*(mid-l+1)]; 
    }
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int n, q; cin >> n >> q; 
    startTime = endTime = a = vector<int>(n, 0); 
    g = vector<vector<int>>(n); 
    st = vector<long long>(2*n, 0); 

    for(int i = 0; i <n ; ++i){
        cin >> a[i]; 
    }

    for(int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v; 
        --u; --v; 
        g[u].push_back(v); 
        g[v].push_back(u); 
    }
    dfs(0, 0); 
    build(0, 0, n-1);

    for(int i = 0; i < q; ++i){
        int t; cin >> t; 
        if(t == 1){
            int u; long long v; cin >> u >> v;    
            --u; 
            //cout << "UPD " << startTime[u] << " " << v << "\n"; 
            upd(0, 0, n-1, startTime[u], v); 
        }
        else{
            int u; cin >> u; 
            --u; 
            //cout << "QUERY " << startTime[u] << " " << endTime[u] - 1 << "\n";
            cout << query(0, 0, n-1, startTime[u], endTime[u]-1) << "\n"; 
        }
    }
    return 0;
}