/*
AC (editorial)
1845D
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        long long a[n], psa[n];
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
            psa[i] = a[i]; 
            if(i) psa[i] += psa[i-1];
        }
        int l = 0, bl = 0;
        long long sum = 0, bsum = 0; 
        for(int i = 0; i < n; i++){
            sum += a[i];
            if(sum < bsum){
                bl = l, bsum = sum;
            }
            if(sum >= 0){            
                sum = 0;
                l = i; 
            }
        }
        if(psa[bl] <= 0) cout << 0 << "\n";
        else cout << psa[bl]<<"\n";
    }
    return 0;
}