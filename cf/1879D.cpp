/*
1879D
*/

#include <iostream>

using namespace std;

long long mod = 998244353; 

int main(){
    cin.tie(0); 
    ios::sync_with_stdio(0);
    int n; cin >> n; 
    long long a[n]; 
    for(int i =0; i < n; i++){
        cin >> a[i]; 
    }
    long long ans = 0; 
    //fwd direction first
    for(int j = 0; j < 31; j++){
        long long numi = 0, len = 0;
        for(long long i = 0; i < n; i++){
            if(a[i] & (1<<j)){
                numi = i - numi; // number intervals at previous which end with 0
                len = (((i)*(i+1))/2) - len; // length of total which end with 0 
                //cout << len << " "; 
                numi++; 
                len += numi; 
                ans += (len % mod)*(1<<j); 
                ans %= mod;                 
            }
            else{
                //cout << len << " "; 
                len += numi;
                ans += (len% mod)*(1 << j); 
                ans %= mod; 
            }
        }
        //cout << "\n";
    }
    cout << ans << "\n";



    return 0;
}