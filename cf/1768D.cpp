/*
1768D
wip 
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int t; cin >> t; 
    while(t--){ 
        int n; cin >> n; 
        int a[n+1] = {}, p[n+1] = {};
        int miss = 0, mod = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i]; 
        
            p[a[i]] = i; 
            if(i != a[i]){
                miss++;
                if(a[i] == i-1 && a[i-1] == i) mod = max(mod, 4);
                if(a[i] == i-1 || a[i] == i+1) mod = max(mod, 3);
            }
        }
        cout << miss << " " << mod <<"\n";
        int ans = (miss - mod + (miss % 2))/2 + 1; //worst case 
        cout << max(ans, 0) << "\n"; 
    }
    return 0;
}