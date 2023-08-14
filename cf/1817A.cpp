/*
1817A
AC
*/

#include <iostream>
#include <vector>

using namespace std; 

struct Info{
    int len, l, r, lf, rf; 
};

vector<Info> st; 
int n, q; 
vector<int> a; 


Info merge(Info al, Info ar){
    if(al.len == -1) return ar; 
    if(ar.len == -1) return al; 
    Info ret = {al.len + ar.len, al.l, ar.r, al.lf, ar.rf};
    if(al.r >= ar.l){
        
        ret.len -= al.rf + ar.lf; 
        if(al.len == 1) ret.lf = 1; 
        if(ar.len == 1) ret.rf = 1; 
    }
    return ret; 
}

void build(int idx, int l, int r){
    if(l == r){
        st[idx] = {1, a[l], a[r], 0, 0};
        return; 
    }
    int li = idx*2, ri = li + 1; 
    int m = (l+r)/2; 
    build(li, l, m); 
    build(ri, m+1, r);

    st[idx] = merge(st[li], st[ri]);
    //cout << "Best of " << l << " " << r << " is " <<st[idx].len << "\n"; 
}



Info query(int idx, int l, int r, int ql, int qr){
    if(l > qr || r < ql) return {-1, 0, 0, 0, 0};

    if(ql <= l && qr >= r){
        return st[idx];
    }
    else{
        int m = (l+r)/2; 
        return merge(query(2*idx, l, m, ql, qr), query((2*idx) + 1, m+1, r, ql, qr));
    }
}


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n >>  q; 
    a.resize(n); 
    st.resize(4*n); 

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    build(1, 0, n-1); 

    for(int i = 0; i < q; i++){
        int ql, qr; cin >> ql >> qr; 
        ql--; qr--; 
        Info ans = query(1, 0, n-1, ql, qr);
        cout << ans.len << "\n";
    }
    return 0;
}