/*
1793D
ac
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n; 
    vector<long long> p(n), q(n), lp(n+1), lq(n+1); 
    for(int i = 0; i < n; i++){
        cin >> p[i];
        lp[p[i]] = i; 
    }
    for(int i = 0; i < n; i++){
        cin >> q[i]; 
        lq[q[i]] = i;
    }
    long long lo = min(lp[1], lq[1]), hi = max(lp[1], lq[1]); 
    long long ans = ((lo * (lo+1))/2);
    ans +=(((hi -lo - 1) * (hi-lo))/2);
    ans +=(((n - hi - 1) * (n-hi))/2);
    ans++; //1 for complete array
    for(int i = 2; i <= n; i++){
        long long nlo = min(lp[i], lq[i]), nhi = max(lp[i], lq[i]);
        
        if(nlo < lo && nhi > hi){
            ans += (lo - nlo) * (nhi - hi);
        }
        else if(nlo > hi){
            ans += (lo+1) * (nlo - hi);

        }
        else if(nhi < lo){
            ans += (lo - nhi) * (n- hi);
        }
        hi = max(hi, nhi); 
        lo = min(lo, nlo);
    }
    cout << ans << "\n";

    return 0;
}