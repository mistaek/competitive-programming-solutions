/*
992E
*/

#include <iostream>
#include <vector>
 
using namespace std; 

vector<long long> stmax, stsum; 
vector<long long> a;

void build(int i, int l, int r){

    if(l == r){
        stmax[i] = stsum[i] = a[l];
        return; 
    }

    int mid = (l+r)/2; 
    build(i+1, l, mid); 
    build(i + 2*(mid - l + 1), mid + 1, r);

    stmax[i] = max(stmax[i+1], stmax[i+2*(mid - l + 1)]); 
    stsum[i] = stsum[i+1] + stsum[i+2*(mid-l+1)];
    //cout << i << " " << l << " " << r  << " " << st[i].second << "\n";
}

void update(int i, int l, int r, int ql, int qr, long long v){
    //cout << i << " " << l << " " << r << " " << ql << " " << qr << " " << v << "\n";

    if(ql > qr) return;
    if(l == ql && r == qr){
        
        stsum[i] = v; //
        stmax[i] = v; 
        return ;
    }

    int mid = (l+r)/2; 
    update(i+1, l, mid, ql, min(qr, mid), v); 
    update(i+2*(mid - l + 1), mid + 1, r, max(ql, mid + 1), qr, v); 
    
    stmax[i] = max(stmax[i+1], stmax[i+2*(mid - l + 1)]); 
    stsum[i] = stsum[i+1] + stsum[i+2*(mid-l+1)];
}

long long query(int i, int l, int r, int ql, int qr){
    if(ql > qr) return 0;
    if(l == ql && r == qr){
        return stsum[i]; 
    }

    int mid = (l+r)/2; 
    return query(i+1, l, mid, ql, min(qr, mid)) + query(i+2*(mid-l+1), mid+1, r, max(ql, mid+1), qr); 
}

int mquery(int i, int l, int r, int ql, int qr, long long s){ //find first index in range which has value >= s
    if(ql > qr) return 1e6;
    if(r == l) return l;
    int mid = (l+r)/2; 
    if(stmax[i] < s) return 1e6;
    int ans = 1e6; 
    if(stmax[i+1] >= s){
        ans = mquery(i+1, l, mid, ql, min(mid, qr), s);
    }
    if(ans == 1e6 && stmax[i + 2*(mid - l + 1)] >= s){
        ans = mquery(i+2*(mid - l + 1), mid+ 1,r, max(mid+1, ql), qr,  s);
    }

    return ans; 
   
}

int main(){
    /*
    test(); 
    return 0;
    //*/
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n, q; cin >> n >> q; 
    a = vector<long long>(n); 
    stsum = stmax = vector<long long>(2*n);

    for(int i = 0; i <n; ++i){
        cin >> a[i]; 
    }

    build(0, 0, n-1);
    for(int i = 0; i < q; ++i){
        long long ind, nv; 
        cin >> ind >> nv; 
        --ind; 
        update(0, 0, n-1, ind, ind, nv);
        a[ind] = nv; 
        int nextpos = 0;
        while(nextpos < n){
            long long s = query(0, 0, n-1, 0, nextpos-1);
            if(a[nextpos] == s){
                break; 
            }
            else{
                //bsearch for nextpos
                s += a[nextpos];
                nextpos = mquery(0, 0, n-1, nextpos+1, n-1, s);
            }
        }
        if(nextpos >= n) cout << "-1\n";
        else cout << nextpos + 1 << "\n";
    }
    return 0;
}