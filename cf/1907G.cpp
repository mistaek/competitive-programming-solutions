/*
1907G
AC
*/

#include <iostream>
#include <vector>

using namespace std; 

vector<int> a, s, v, indeg, cck; 
vector<int> out; 
vector<int> cckv; 
int cchk(int i, int d){
    if(cck[i]) return i; 
    cck[i] = 1; 
    if(s[i] && d){
        cckv.push_back(d);
        cchk(a[i], 1); 
        return i; 
    }
    else return cchk(a[i], d+1);

}
void dfs(int u){
    if(v[u]) return; 
    v[u] = 1; 
    if(s[u]){
        out.push_back(u); 
        s[u] = 0; 
        s[a[u]] = 1 - s[a[u]]; 
    }
    if(!--indeg[a[u]]){
        dfs(a[u]);
    }
}

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        cck = a = s = v = indeg = vector<int> (n+1, 0);
        out.clear();
        for(int i = 1; i <= n; i++){
            char c; cin >> c; 
            s[i] = c - '0';
        }
        for(int i = 1; i <= n; i++){
            cin >> a[i]; 
            ++indeg[a[i]];
        }

        for(int i = 1; i <= n; i++){
            if(indeg[i] == 0 && !v[i]){
                dfs(i);
            }
        }

        bool pos = true; 
        for(int i = 1; i <= n; i++){
            if(!v[i]&& s[i]){
                cckv.clear();
                int nxt = cchk(a[i], 1);
                if(cckv.size() % 2) pos = false; 
                else{
                    int even = 0, odd = 0;
                    for(int j = 0; j < cckv.size(); j+= 2){
                        even += cckv[j];
                        odd += cckv[j+1];
                    }
                    if(even <= odd){
                        dfs(i); 
                    }
                    else dfs(nxt);
                }
            }
        }

        if(pos){
            cout << out.size() << "\n"; 
            for(int i = 0; i < out.size(); i++){
                if(i) cout << " "; 
                cout << out[i];
            }
            cout << "\n"; 
        }
        else cout << "-1\n";

    }

    return 0;
}