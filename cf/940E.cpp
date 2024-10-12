/*
940E
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<long long> psa, a, st, best; 

void build(int i, int l, int r)
{
    if(l == r) st[i] = a[l];
    else
    {
        int mid = (l+r)/2; 
        build(i+1, l, mid);
        build(i + 2*(mid - l + 1), mid+1, r);
        st[i] = min(st[i+1], st[i+2*(mid - l+1)]);
    }
}

long long query(int i, int l, int r, int ql, int qr)
{
    if(ql > qr) return 1e15;
    if(ql == l && qr == r) return st[i];
    
    int mid = (l+r)/2; 
    return min(query(i+1, l, mid, ql, min(qr, mid)), query(i+2*(mid-l+1), mid+1, r, max(ql, mid+1), qr));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c; cin >> n >> c; 
    a = vector<long long>(n); 
    psa = vector<long long>(n);
    st = vector<long long>(2*n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        psa[i] = a[i]; 
        if(i) psa[i] += psa[i-1];
    }

    build(0, 0, n-1);
    best = vector<long long>(n+1, 0);
    for(int i = n-1; i >=0; --i){
        best[i] = a[i] + best[i+1];
        if(i + c - 1 <= n-1){
            long long part = psa[i+c-1] - (i ? psa[i-1] : 0) - query(0, 0, n-1, i, i+c-1) + best[i+c]; 
            best[i] = min(part, best[i]);
        }
    }
    cout << best[0] << "\n";
    return 0;
}