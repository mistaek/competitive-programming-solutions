/*
1717C
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int t; 
    cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> a(n), b(n); 
        for(int i = 0; i < n; i++){
            cin >> a[i]; 
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        bool ans = true; 
        for(int i = 0; i < n; i++){
            if(a[i] == b[i]) continue;
            if(a[i] > b[i]) ans = false; 
            if(b[i] > b[(i+1) % n] + 1) ans = false;   
        }
        if(ans) cout << "YES\n"; 
        else cout << "NO\n";
    }
    
    
    return 0;
}