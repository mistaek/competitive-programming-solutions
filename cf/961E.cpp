/*
961E
AC, had a tiny bug..
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 
vector<long long> sz;
vector<vector<long long>> st; 


long long checkv(vector<long long>& vec, long long v){
    auto it = lower_bound(vec.begin(), vec.end(), v);
    return it - vec.begin();
}
void build(long long i, long long l, long long r){
    if(l == r) st[i].push_back(sz[l]);
    else{
        long long mid = (l+r)/2; 
        build(i+1, l, mid);
        build(i + 2*(mid-l+1), mid+1, r);
        merge(st[i+1].begin(), st[i+1].end(), st[i+2*(mid-l+1)].begin(), st[i+2*(mid-l+1)].end(), back_inserter(st[i]));
    }
}

// find the number of elements ql <= qr such that sz[ql] < v
long long query(long long i, long long ql, long long qr, long long l, long long r, long long v){
    if(qr < ql) return 0;
    if(ql > r || qr < l) return 0;
    if(ql == l && qr == r){
        return checkv(st[i], v);
    }
    
    long long mid = (l+r)/2;
    return query(i+1, ql, min(qr, mid), l, mid, v) + query(i+2*(mid-l+1), max(ql, mid+1), qr, mid+1, r, v);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n; cin >>n; 
    sz = vector<long long>(n);
    st = vector<vector<long long>>(2*n);
    for(long long i = 0; i < n; ++i){
        cin >> sz[i];
        --sz[i];
    }

    build(0, 0, n-1);
    long long ans = 0;

    for(long long i = 0; i < n; ++i){
        if(sz[i] < i) continue; 
        ans += min(sz[i], n-1) - i; 
        ans -= query(0, i+1, min(sz[i], n-1), 0, n-1, i);
    }

    cout << ans << "\n";
    return 0;
}