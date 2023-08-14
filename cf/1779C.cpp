/*
1779C
AC
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--){
        long long n, m; cin >> n >> m; 
        m--;
        long long a[n], psa[n]; 
        for(int i = 0; i < n; i++){
            cin >> a[i];
            psa[i] = a[i]; 
            if(i) psa[i] += psa[i-1];
        }
        long long ans = 0;
        //post m 
        priority_queue<long long> inc; 
        long long mod = 0;
        for(int i = m+1; i< n; i++){
            if(a[i] < 0){
                inc.push(-a[i]); 
            }
            while(psa[i] - psa[m] + mod< 0){
                ans++; 
                mod += 2*inc.top(); 
                inc.pop();
            }
        }

        //pre m
        priority_queue<long long> dec; 
        for(int i = m-1; i >= 0; i--){
            if(a[i+1] > 0){
                dec.push(a[i+1]);
            }
            while(psa[i] - psa[m] < 0){
                ans++; 
                psa[m] -= 2*dec.top();
                dec.pop();
            }
        }
        cout << ans << "\n";
    }
    return 0;
}