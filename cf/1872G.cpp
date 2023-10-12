/*
1872G
*/

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std; 

int main(){
    cin.tie(0); 
    ios::sync_with_stdio(0); 

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<long long> a(n), p(n,1),  ps(n, 0); 
        vector<int> nz; 
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > 1) nz.push_back(i); 
        }
        bool b = false; 
        for(int i = 0; i < n; i++){
            ps[i] += a[i]; 
            p[i] *= a[i];
            if(i){
                p[i] *= p[i-1]; 
                ps[i] += ps[i-1]; 
            }
            if(p[i] > INT_MAX){
                b = true; break; 
            }
        }
        if(b) cout << nz[0]+1 << " " << nz[nz.size() -1]+1 << "\n"; 
        else{
            long long bans = 0, l = 1, r = 1; 
            for(int i = 0; i < nz.size(); i++){
                for(int j = i; j < nz.size(); j++){
                    long long ans = 0; 
                    if(nz[i]) ans += p[nz[j]]/p[nz[i]-1] + ps[nz[i]-1]; 
                    else ans += p[nz[j]]; 
                    if(nz[j] < n-1) ans += ps[n-1] -  ps[nz[j] + 1];
                    //cout << nz[i] << " " << p[nz[i]] << " " << ps[nz[j] + 1] << " " << ans << "\n";

                    if(ans > bans){bans = ans;  l = nz[i]+1, r = nz[j]+1;}                   
                }
            }
            cout << l  << " " << r  << "\n";
        }
    }
    return 0;
}