/*
1023D
AC, underestimated
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std; 

vector<int> st; 
vector<int> a; 
void build(int i, int l, int r){
    if(l == r){
        st[i] = a[l];
    }
    else{
        int m = (l+r)/2; 
        build(i+1, l, m); 
        build(i+2*(m-l+1), m+1, r); 
        st[i] = min(st[i+1], st[i+2*(m-l+1)]); 
    }
}

int query(int i, int l, int r, int ql, int qr){
    if(ql > qr) return 1e9; 
    if(l == ql && r == qr) return st[i]; 
    
    int m = (l+r)/2; 
    return min(query(i+1, l, m, ql, min(qr, m)), query(i+2*(m-l+1), m+1, r, max(ql, m+1), qr));
}

int main(){
    int n, q; cin >> n >> q; 
    a = vector<int>(n);
    st = vector<int>(2*n, 0); 
   
    bool seenq = false; //MUST SEE Q;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] == q) seenq= true; 
    
    }
    //deal with 0s first
    //if we haven't seen q, then set the first 0 to q
    int lastseen = 0, firstseen = 0;
    if(!seenq){
        for(int i = 0; i < n; ++i){
            if(a[i] == 0){
                a[i] = q; 
                break; 
            }
        }  
    }

    for(int i = 0; i < n; ++i){
        if(!firstseen && a[i]) firstseen = a[i];
        if(a[i]) lastseen = a[i]; 
        else a[i] = lastseen;
    }
    for(int i = 0 ; i <n; ++i){
        if(!a[i]) a[i] = firstseen;
    }
    
    build(0, 0, n-1); 
    vector<pair<int, int>> fl(q+1, {n, -1});
    for(int i = 0; i < n; ++i){
        fl[a[i]].first = min(fl[a[i]].first, i); 
        fl[a[i]].second = max(fl[a[i]].second, i);
    }

    bool pos = true; 
    if(fl[q].first > fl[q].second) pos = false; 
    for(int i = q; i >= 1; --i){
        if(!pos) break; 
        if(query(0, 0, n-1, fl[i].first, fl[i].second) < i){
            pos = false; 
        }
    }

    if(pos){
        cout << "YES\n";
        for(int i = 0; i < n; ++i){
            if(i) cout << " "; 
            cout << a[i];
        }
        cout << "\n";
    }
    else cout << "NO\n";

    return 0;
}