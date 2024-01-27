/*
474F
*/

#include <iostream>
#include <vector>

#include <iostream>

using namespace std; 

vector<pair<int, int>> st; 
vector<int> a; 

int gcd(int a, int b){
    if(b == 0) return a; 
    return gcd(b, a%b); 
}

void build(int i, int l, int r){
    if(l == r){
        st[i] = {a[l], 1};
        return; 
    }
    int mid = (l+r)/2; 
    build(i + 1, l, mid); build(i + 2*(mid - l + 1), mid +1, r);
    st[i].first = gcd(st[i+1].first, st[i + 2 * (mid - l + 1)].first); 
    if(st[i].first == st[i+1].first) st[i].second += st[i+1].second; 
    if(st[i].first == st[i+2*(mid - l + 1)].first) st[i].second += st[i + 2*(mid - l+1)].second; 
}

pair<int, int> query(int i, int ql, int qr, int l, int r){
    if(ql == l && qr == r) return st[i]; 

    int mid = (l+r)/2; 
    if(ql > mid) return query(i + 2 * (mid - l + 1), ql,  qr, mid+1, r);
    else if(qr <= mid) return query(i +1, ql, qr, l, mid);
    else{
        pair<int, int> q1 = query(i+1, ql, mid, l, mid), q2 = query(i+ 2*(mid - l + 1), mid+1, qr, mid+1, r);
        int g = gcd(q1.first, q2.first);
        int tot = 0; 
        if(q1.first == g) tot += q1.second; 
        if(q2.first == g) tot += q2.second; 
        return {g, tot};
    }
}


int main(){
    int n; cin >> n; 
    st = vector<pair<int, int>>(2*n, {0,0});
    a = vector<int>(n); 
    for(int i = 0; i < n; i++){
        cin >> a[i]; 
    }
    build(0, 0, n-1);
    int t; cin >> t; 
    while(t--){
        int l, r; cin >> l >> r; 
        --l, --r; 
        cout << r - l + 1 - query(0, l, r, 0, n-1).second << "\n";
    }
    return 0;
}