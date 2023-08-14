/*
1792D
ac
*/

#include <iostream>
#include <algorithm>
#include <memory>
using namespace std; 


struct ptree {
    shared_ptr<ptree> nxt[11] = {}; 
    void insert(int n){
        if(nxt[n] != nullptr) return; 
        else nxt[n] = make_shared<ptree>();
    }
    bool has(int n){
        return nxt[n] != nullptr;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m; 
        int a[n][m+1] = {};
        shared_ptr<ptree> root = make_shared<ptree>(); 
        for(int loopylooper = 0; loopylooper < n; loopylooper++){
            int s[m+1] = {};
            for(int i = 1; i <= m; i++){
                cin >> a[loopylooper][i]; 
                s[a[loopylooper][i]] = i;
            }
            shared_ptr<ptree> branch = root; 
            for(int i = 1; i <= m; i++){
                branch->insert(s[i]);
                branch = branch->nxt[s[i]];
            }
            

        }
        for(int j= 0; j < n; j++){
            if(j) cout << " "; 
            int ans = 0; 
            shared_ptr<ptree> branch = root; 
            int i = 1;
            while(i <= m){
                if(!branch->has(a[j][i])) break;
                branch = branch->nxt[a[j][i]]; 
                ans++; 
                i++;
            }
            cout << ans;
            
        }
        cout << "\n";
    }
    return 0; 
}