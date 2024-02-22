/*
1925E (also 1924B)
AC
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std; 

vector<long long> st, updL, markedL, markedR;
set<pair<long long, long long>> loc;

long long m, n, q; 

void build(int i, long long l, long long r){
    if(l == r){
        auto lb = loc.lower_bound({l, 0});
        if(lb->first == l){ //prevent prev(begin) just in case
            st[i] = 0;
            return; 
        }
        auto pr = prev(lb);
        st[i] = pr->second * (lb->first - l);
        return;
    }

    int mid = (l+r)/2; 
    build(i+1, l, mid); 
    build(i+ 2*(mid - l + 1), mid+1, r);
    st[i] = st[i+1] + st[i+2*(mid-l+1)];
}

void push(int i, long long l, long long r){
   if(l >= r) return; 
   if(markedL[i]){
        long long mid = (l+r)/2;
        st[i+1] += (mid - l + 1) * updL[i];
        st[i+2*(mid - l + 1)] += (r - mid) * updL[i];
        updL[i+1] += updL[i];
        updL[i+2*(mid-l+1)] += updL[i]; 
        markedL[i+1] = markedL[i+2*(mid-l+1)] = 1; 
        updL[i] = 0;
        markedL[i] = 0;
    }
    if(markedR[i]){
        long long mid = (l+r)/2; 
        auto lb = loc.lower_bound({r, 0});
        auto pr = prev(lb);
        if(pr->first > l) cout << "ERROR\n"; 
        //dist = lb->first - l + lb->first - l+1 ...
        long long diff1 = (mid - l + 1) * lb->first, diff2 = (r - mid) * lb->first; 
        diff1 -= (mid*(mid+1))/2; 
        diff1 += (l * (l-1))/2; 
        diff2 -= (r * (r+1))/2; 
        diff2 += (mid*(mid+1))/2; 
        st[i+1] = diff1 * pr->second;
        st[i+2*(mid - l + 1)] = diff2 * pr->second; 
        markedR[i+1] = markedR[i+2*(mid-l+1)] = 1; 
        markedR[i] = 0;
    }
}

long long query(int i, int ql, int qr, long long l, long long r){
    if(ql == l && qr == r){
        return st[i];
    }
    push(i, l, r);
    long long mid = (l+r)/2; 
    if(ql > mid) return query(i+2*(mid-l+1), ql, qr, mid+1, r); 
    else if(qr <= mid) return query(i+1, ql, qr, l, mid);
    else{
        return query(i+2*(mid-l+1), mid+1, qr, mid+1, r) + query(i+1, ql, mid, l, mid);
    }
}

void updateLeft(int i, int ql, int qr, long long l, long long r, long long chg){
    //cout << l << " " << r << " " << chg << "\n";
    if(l > r || ql > qr) return; 
    if(ql == l && qr == r){
        st[i] += (r - l + 1LL) * chg;
        updL[i] += chg; 
        markedL[i] = 1; 
        return; 
    }
    push(i, l, r);
    int mid = (l+r)/2; 
    updateLeft(i+1, ql, min(qr, mid), l, mid, chg);
    updateLeft(i+2*(mid-l+1), max(ql, mid+1), qr, mid+1, r, chg);
    st[i] = st[i+1] + st[i+2*(mid-l+1)];
}

void updateRight(int i, int ql, int qr, long long l, long long r){
    if(l > r || ql > qr) return; 
    if(ql == l && qr == r){
        auto lb = loc.lower_bound({r, 0});
        auto pr = prev(lb); 
        if(pr->first > l) cout << "ERROR";//should never happen
        long long diff = (long long)(r-l+1) * lb->first;
        diff -= (r * (r+1))/2LL; 
        diff += (l * (l-1))/2LL; 
        st[i] = diff * pr->second;
        markedR[i] = 1; 
        return;
    }
    push(i, l, r);
    int mid = (l+r)/2; 
    updateRight(i+1, ql, min(qr, mid), l, mid);
    updateRight(i+2*(mid-l+1), max(ql, mid+1), qr, mid+1, r);
    st[i] = st[i+1] + st[i+2*(mid-l+1)];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> q; 
    vector<long long> x(m), v(m); 
    for(int i = 0; i < m; i++){
        cin >> x[i]; 
    }
    for(int i = 0; i < m; i++){
        cin >> v[i];
        loc.insert({x[i], v[i]});
    }

    st = vector<long long>(2*n), updL = vector<long long>(2*n, 0), markedL = vector<long long>(2*n, 0), markedR = vector<long long>(2*n, 0); 
    build(0, 1, n);
    for(int i = 0; i < q; i++){
        int t; cin >> t; 
        if(t == 1){
            long long nx, nv; cin >> nx >> nv; 
            auto lb = loc.lower_bound({nx, nv});
            auto pr = prev(lb);
            updateLeft(0, pr->first + 1, nx, 1, n, -(lb->first - nx) * pr->second);
            loc.insert({nx, nv});

            updateRight(0, nx+1, lb->first -1, 1, n);

        }
        if(t == 2){
            long long l, r; cin >> l >> r; 
            cout << query(0, l, r, 1, n) << "\n";
        }
    }
    return 0;
}