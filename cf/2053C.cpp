/*
2053C
*/

#include <iostream>
#include <vector>
using namespace std; 

long long n, k, ans; 
long long modtotal = 0, modnum = 0;
int count = 0;

void solve(long long l, long long r){
    //cout << l << " " << r << "\n";
    //if(r - l + 1 >= k) cout << r - l + 1 << " " << k << " pass\n";

    if((r - l + 1) < k) return; 

    long long m = (l+r)/2;
    if((r - l + 1) % 2LL){
        ans += m * (modnum + 1) + modtotal; 
        modtotal += m * (modnum+1) + modtotal; 
        modnum = 2*modnum + 1; 
        if(l != r) solve(l, m-1);
    }
    else{
        modtotal += m * (modnum+1) + modtotal; 
        modnum = 2*modnum + 1; 
        if(l != r) solve(l, m);
    }
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int t; cin >> t; 
    while(t--){
        cin >> n >> k; 
        ans = 0; modnum = 0; modtotal=0;
        solve(1, n); 
        cout << ans << "\n";
    }
    return 0;
}