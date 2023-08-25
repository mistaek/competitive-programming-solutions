/*
1857E
AC
*/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        long long cd[n], sorted[n];
        
        for(int i = 0; i < n; i++){
            cin >> cd[i];
            sorted[i] = cd[i];
        }
        sort(sorted, sorted + n);
        long long a[n]= {}, b[n] = {}; 
        for(long long i = 1; i <n; i++){
            a[i] = a[i-1] +  (i * (sorted[i] - sorted[i-1]));
        }
        for(long long i = n-2; i >= 0; i--){
            b[i] = b[i+1] + ((n - i -1) * (sorted[i+1] - sorted[i]));
        }
        map<long long, long long> ans; 
        for(int i = 0; i < n; i++){
            ans[sorted[i]] = a[i] + b[i] + n;
        }
        for(int i = 0; i < n; i++){
            if(i) cout << " "; 
            cout << ans[cd[i]]; 
        }
        cout << "\n";
    }
    return 0;
}