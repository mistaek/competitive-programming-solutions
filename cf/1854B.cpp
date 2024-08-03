/*
1854B
AC, used editorial, first bitset problem
*/

#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);

    int n; cin >> n; 
    long long a[2*n], ps[2*n] = {}; 
    for(int i = 0; i < n; i++){
        cin >> a[i]; 
        ps[i] = a[i]; 
        if(i) ps[i] += ps[i-1]; 
    }
    for(int i = n; i < 2*n; i++) ps[i] += ps[i-1]; 

    bitset<200000> ans = {1}; 
    long long mx = 0;
    for(int i = 0; i < n; i++){
        ans |= ans << a[i]; 
        if(ans[i]){
            mx = max(mx, ps[i] - i);
            ans[i] = 0;
        }
    }

    for(int i = 0; i < 2*n; i++){
        if(ans[i]) mx = max(mx, ps[i] - i);
    }

    cout << mx << "\n";
      
    return 0;
}