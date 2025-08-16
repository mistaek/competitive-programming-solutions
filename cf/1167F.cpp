/*
1167F
AC
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

vector<long long> st, a, pos;

long long MOD = 1e9+7; 
// add v to all in [ql, qr]
void upd(int i, int l, int r, int ql, int qr, int v){
    if(ql > qr) return; 
    if(ql == l && qr == r){
        st[i] += v; 
    }
    else{
        int m = (l+r)/2; 
        upd(i+1, l, m, ql, min(qr, m), v);
        upd(i+2*(m - l+ 1), m+1, r, max(m+1, ql), qr, v); 
    }
}

void push(int i, int l, int r){
    // don't really care about middle nodes anyway
    if(l == r){
        return; 
    }
    int m = (l+r)/2; 
    st[i+1] += st[i]; 
    st[i+2*(m - l + 1)] += st[i];
    st[i] = 0; 
}

long long query(int i, int l, int r, int q){
    if(q < l || q > r) return 0; 
    if(l == q && r == q) return st[i]; 
    if(st[i]) push(i, l, r); 
    int m = (l+r)/2; 
    return query(i+1, l, m, q) + query(i+2*(m-l+1), m+1, r, q); 
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    long long n; cin >> n; 
    auto sorted = vector<pair<long long, int>>(n); 
    pos = a = vector<long long >(n); 
    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
        sorted[i] = {a[i], i}; 
    }
    sort(sorted.begin(), sorted.end()); 
    for(int i = 0; i < n; ++i) pos[sorted[i].second] = i; 

    st = vector<long long>(2*n, 0); 
    long long ans = 0; 
    for(long long i = 0; i < n; ++i){
        long long qty = 0; 
        qty += (i + 1) * (n-i); // base value
        qty %= MOD; 
        qty += query(0, 0, n-1, pos[i]) *(n-i); // sum g(0..i, i, a[i])
        qty %= MOD; 
        qty *= a[i]; 
        qty %= MOD; 
        ans +=qty; 
        ans %= MOD; 
        upd(0, 0, n-1, pos[i], n-1, i+1); 
    }
    // reset
    st = vector<long long>(2*n, 0); 
    for(long long i = n-1; i >= 0; --i){
        long long qty = query(0, 0, n-1, pos[i]) *(i + 1) % MOD;
        qty *= a[i]; qty %= MOD; 
        ans += qty; ans %= MOD; 
        upd(0, 0, n-1, pos[i], n-1, n-i);
    }

    cout << ans << "\n"; 

    return 0;
}