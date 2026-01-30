/*
1179C
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<int> a, b; 
vector<int> st, lz; 

void push(int i, int l, int r) {
    if(l != r){
        int m = (l+r)/2; 
        lz[i+1] += lz[i]; 
        lz[i+2*(m-l+1)] += lz[i];
    }
    st[i] += lz[i];
    lz[i] = 0; 
}

void update(int i, int l, int r, int ql, int qr, int v){
    if(qr < l || ql > r) return; 
    
    if(l == ql && r == qr){
        lz[i] += v; 
        return;
    }
    push(i, l, r); 
    int m = (l+r)/2; 
    update(i+1, l, m, ql, min(qr, m), v);
    update(i+2*(m - l + 1), m+1, r, max(ql, m+1), qr, v);
    st[i] = max(st[i+1] + lz[i+1], st[i+2*(m - l + 1)] + lz[i+2*(m-l+1)]) + lz[i];
}

// finds the biggest index which is positive
int f(int i, int l, int r){
    push(i, l, r);
    if(st[i] + lz[i] <= 0) return -1;
    if(l == r) return l; 
    int m = (l+r)/2; 
    if(st[i+2*(m-l+1)] + lz[i+2*(m-l+1)] > 0) return f(i+2*(m-l+1), m+1, r); 
    else return f(i+1, l, m);
}

int main() {
    int n, m; cin >> n >> m;
    a = vector<int>(n); b = vector<int>(m);
    st = lz = vector<int>(3e6, 0);
    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
        update(0, 0, 1e6, 0, a[i], 1);
    }
    for(int i = 0; i < m; ++i){
        cin >> b[i]; 
        update(0, 0, 1e6, 0, b[i], -1); 
    }


    int q; cin >> q; 
    for(int i = 0; i < q; ++i){
        int t, idx, x; 
        cin >> t >> idx >> x; 
        --idx;
        if(t == 1){
            update(0, 0, 1e6, 0, a[idx], -1); 
            a[idx] = x; 
            update(0, 0, 1e6, 0, x, 1);
        }
        else{
            update(0, 0, 1e6, 0, b[idx], 1); 
            b[idx] = x; 
            update(0, 0, 1e6, 0, x, -1);
        }
        cout << f(0, 0, 1e6) << "\n";
    }
    return 0;
}