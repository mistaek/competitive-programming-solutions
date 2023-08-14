/*
1779D
ac
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n;
        bool ans = true; 
        vector<int> a(n), b(n), inv;
        inv.push_back(0);
        map<int, int> r, f;
        for(int i = 0; i < n; i++){
            cin >> a[i]; 
        }
        for(int i = 0; i < n; i++){
            cin >> b[i]; 
            if(i && b[i] > b[i-1]) inv.push_back(i);
            if(b[i] > a[i]) ans = false; 
        }
        inv.push_back(n);
        cin >> m; 
        for(int i = 0; i < m; i++){
            int rz; cin >> rz; 
            r[rz]++;
        }

        if(!ans){
            cout <<"no\n";
            continue;
        }
        for(int k = 1; k < inv.size(); k++){
            if(k > 1){
                for(int i = inv[k-2]; i < inv[k-1]; i++){
                    if(f[b[i]]){
                        if(b[i] < b[inv[k-1]]) f[b[i]] = 0;
                    }
                }
            }
            for(int i = inv[k-1]; i < inv[k]; i++){
                if(a[i] == b[i]) continue; 
                else{
                    if(f[b[i]] == 0){
                        f[b[i]] = 1; 
                        if(r[b[i]] == 0){
                            ans = false; 
                            break; 
                        }
                        r[b[i]]--;
                    }
                }
                if(!ans) break; 
            }
            if(!ans) break; 
        }
        if(ans) cout << "yes\n"; 
        else cout << "no\n";
        
    }
    return 0;
}