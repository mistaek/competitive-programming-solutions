/*
1913D
AC, had a problem with mod..
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std; 

vector<pair<long long, long long>> st;
vector<long long> a;
long long ans; 
int n;
long long MOD = 998244353;

void build(int i, int l, int r){
    if(l == r){
        st[i] = {a[l], l};
        return;
    }

    int mid = (l+r)/2; 
    build(i+1, l, mid);
    build(i+ (2*(mid - l + 1)), mid+1, r);

    st[i] = min(st[i+1], st[i+ 2*(mid - l + 1)]);
}

pair<long long, long long> query(int i, int ql, int qr, int l, int r){
    if(ql == l && qr == r){
        return st[i];
    }
    
    int mid = (l + r)/2; 
    if(ql > mid) return query(i+2*(mid - l + 1), ql, qr, mid+1, r);
    else if(qr <= mid) return query(i+1, ql, qr, l, mid);
    else return min(query(i+1, ql, mid, l, mid), query(i+ 2*(mid-l+1), mid+1, qr, mid+1, r));
}

long long solve(int l, int r, int from){
    // 0 = top, 1 = left, 2 = right, 3 = both
    auto p = query(0, l, r, 0, n-1);
    
    long long s1 = 1, s2 = 1; 
    long long ans = 0;
    if(from == 0){
        if(p.second > l) s1 = solve(l, p.second - 1, 2); 
        if(p.second < r) s2 = solve(p.second + 1, r, 1);
        s1 %= MOD; 
        s2 %= MOD;
        ans = s1 * s2; 
        ans %= MOD;

        return ans;
    }
    else if(from == 1){
        if(p.second > l) s1 = solve(l, p.second - 1, 3);
        if(p.second < r) s2 = solve(p.second+1, r, 1); 
        s1 %= MOD; 
        s2 %= MOD;
        ans = s1 * s2;
        ans %= MOD; 

        ans += s2; 
        ans %= MOD;
        return ans;
    }
    else if(from == 2){
        if(p.second > l) s1 = solve(l, p.second - 1, 2);
        if(p.second < r) s2 = solve(p.second+1, r, 3); 
        s1 %= MOD; 
        s2 %= MOD;
        ans = s1 * s2;
        ans %= MOD;
        ans += s1;  
        ans %= MOD;
        return ans;
    }
    else if(from == 3){
        if(p.second > l) s1 = solve(l, p.second - 1, 3);
        if(p.second < r) s2 = solve(p.second+1, r, 3);
        s1 %= MOD; 
        s2 %= MOD;
        ans = s1 * s2;
        ans %= MOD; 
        ans += s1;
        ans %= MOD;
        ans += s2; 
        ans %= MOD; 
        if(ans == 0) ans += MOD;
        ans -= 1LL; 
        ans %= MOD;
        return ans;
    }
    
}

/*
void bfcheck(vector<long long> &a, set<long long> &ss, int msk){
    ss.insert(msk);
    vector<int> cur; 
    for(int i = 0; i < a.size(); i++){
        if(msk & (1 << i)) cur.push_back(i);
    }

    for(int i = 0; i < cur.size(); i++){
        if(i){
           if(a[cur[i]] > a[cur[i-1]]){
                bfcheck(a, ss, msk - (1 << cur[i]));
           }
        }
        if(i < cur.size() - 1){
            if(a[cur[i]] > a[cur[i+1]]){
                bfcheck(a, ss, msk - (1 << cur[i]));
            }
        }
    }
}
*/

int main(){
    int t; 
    cin >> t; 
    while(t--){
        cin >> n; 
        a = vector<long long>(n), st = vector<pair<long long, long long>>(2*n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        build(0, 0, n-1);
        cout << solve(0, n-1, 0) << "\n";

        /*
        set<long long> ss; 
        bfcheck(a, ss, (1 << n) - 1);

        cout << ss.size() << "\n";
        */
    }
    return 0;
}