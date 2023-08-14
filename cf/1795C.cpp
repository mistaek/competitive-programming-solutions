/*
1795
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<long long> a(n, 0), b(n, 0), psa(n, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i]; 
            
        }
        for(int i = 0; i < n; i++){
            cin >> b[i]; 
            psa[i] = b[i]; 
            if(i) psa[i] += psa[i-1];
        }
        
        long long mod[n+1] ={}, ans[n+1] = {};
        for(int i = 0; i < n; i++){
            auto it = lower_bound(psa.begin() + i, psa.end(), a[i] + ((i > 0) ? psa[i-1] : 0));
            mod[it - psa.begin()]++;
            ans[it-psa.begin()]+= min(a[i] + ((i > 0) ? psa[i-1] : 0) - ((it - psa.begin() - 1  >= 0) ? psa[it - psa.begin() - 1] : 0), b[it-psa.begin()]);
            //cout << it - psa.begin() << " " <<  ans[it-psa.begin()] << "\n";
        }
        long long m = 0; 
        /*for(int i = 0; i < n; i++ ) cout << mod[i] << " "; 
        cout << "\n";
        for(int i = 0; i < n; i++ ) cout << ans[i] << " "; 
        cout << "\n";*/
        for(int i = 0; i < n; i++){
            m += mod[i];
            ans[i] += (i- m+1) * b[i];
            
            if(i) cout << " " << ans[i];
            else cout << ans[i];
        }
        cout << "\n";
        
    }
    
    return 0;
}