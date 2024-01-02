/*
1901D
AC
*/

#include <iostream>
#include <algorithm>

using namespace std; 

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;

    long long a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long ans = 1e18;
    long long cl[n] = {}, cr[n] = {};
    for(int i = 0; i < n; i++){
        cl[i] = a[i] + i; 
        cr[n-i-1] = a[n-i-1] + i;
    }
    for(int i = 1; i < n; i++){
        cl[n-i-1] = max(cl[n-i-1], cl[n-i]);
        cr[i] = max(cr[i], cr[i-1]);
    }
    if(n == 1){
        cout << a[0] << "\n";
        return 0;
    }
    /*
    for(int i = 0; i < n; i++){
        cout << cl[i] << " "; 
    }
    cout << "\n";
    for(int i = 0; i < n; i++){
        cout << cr[i] << " "; 
    }
    cout << "\n";
    */
    ans = min(max(a[0], cl[1]), max(a[n-1], cr[n-2]));
    for(int i = 1; i < n-1; i++){
        ans = min(ans, max(max(cl[i+1], cr[i-1]), a[i]));
    }
    cout << ans << "\n";
    
    return 0;
}