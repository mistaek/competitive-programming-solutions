/*
ac
1867D
*/

#include <iostream>

using namespace std; 

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        int a[n+1], vis[n+1] = {}, ctr[n+1] = {};
        for(int i =1; i <= n; i++){
            cin >> a[i]; 
        }
    
        bool pos = true; 
        int cnt = 1;
        for(int i = 1; i<= n; i++){
            if(vis[i] == 0){
                int u = i; int prev = 0;
                while(!vis[u]){
                    vis[u] = 1 + vis[prev];
                    ctr[u] = cnt; 
                    prev = u;
                    u = a[u]; 
                }
                cnt++;
                if(ctr[prev] == ctr[u] && vis[prev] - vis[u] +1!= k){
                    pos = false;
                }

            }
            if(k == 1 && a[i] != i) pos = false;
        }

        if(pos) cout << "YES\n"; 
        else cout << "NO\n";
        

    }
    return 0;
}