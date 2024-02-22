/*
1930C
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std; 

vector<long long> a; 
/*
vector<pair<long long, long long>> st;
vector<long long> upd

void build(int idx, int l, int r){
    if(l == r){
        st[idx] = {a[l] + l, l};
        return; 
    }

    int mid = (l+r)/2; 
    build(idx+1, l, mid); 
    build(idx+ 2*(mid - l + 1), mid+1, r);
    if(st[idx+1].first >= st[idx+ 2*(mid - l + 1)].first){
        st[idx] = st[idx+1]; 
    }
    else{
        st[idx] = st[idx+ 2*(mid - l + 1)];
    }
}

void push(int idx, int l, int r){
    if(upd[idx]){
        if(l != r){
            int mid = (l+r)/2; 
            upd[idx+1] += upd[idx];
            upd[idx + 2*(mid - l+ 1)] += upd[idx]; 
        }
        upd[idx] = 0; 
    }
}

pair<long long, long long> query(int idx, int l, int r, int ql, int qr){
    if(ql > qr) return {0, 0}; 
    if(l == ql && r == qr){
        return st[idx];
    }
    push(idx, l, r);
    int mid = (l+r)/2; 
    auto p1 = query(idx+1, l, mid, ql, min(qr, mid));
    auto p2 = query(idx + 2*(mid - l + 1), mid+1, r, max(mid+1, ql), qr);
    if(p1.first >= p2.first) return p1; 
    else return p2; 
}

void update(int idx, int l, int r, int ql, int qr, int chg){
    if(ql > qr) return; 
    if(l == ql && r == qr){
        st[idx].first -= chg; 
        upd[idx] += chg; 
        return; 
    }
    
    int mid = (l+r)/2; 
    update(idx+1, l, mid, ql, min(mid, qr), chg);
    update(idx + 2*(mid - l+1), mid+1, r, max(mid+1, ql), qr, chg);
    if(st[idx+1].first >= st[idx+ 2*(mid - l + 1)].first){
        st[idx] = st[idx+1]; 
    }
    else{
        st[idx] = st[idx+ 2*(mid - l + 1)];
    }
}
*/
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0); 
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        a = vector<long long>(n); 
        /*upd = vector<long long>(2*n, 0);
        st = vector<pair<long long, long long>>(2*n);*/
        /*auto comp = [](pair<long long, long long> a, pair<long long, long long> b){
                            if(a.first < b.first) return true; 
                            return (a.second > b.second);
                        };
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, decltype(comp)> pq(comp); */
        
        priority_queue<long long> pq; 
        for(int i = 0; i < n; i++){ 
            cin >> a[i];
            pq.push(a[i] + i + 1);
        }
        long long mx = 1e15;
        while(!pq.empty()){
            auto n = pq.top(); pq.pop();
            n = min(n, mx); 
            cout << n << " "; 
            mx = n -1; 
        }
        cout << "\n";
    }
    return 0;
}