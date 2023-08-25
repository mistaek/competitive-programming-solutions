/*
1851E
AC
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

long long calc(int i, vector<vector<int>> &mix, vector<long long> &c, vector<long long> &v){
    if(v[i]) return c[i];
    else{
        long long ans = 0; 
        for(auto p : mix[i]){
            ans += calc(p, mix, c, v); 
        }
        c[i] = min(c[i], ans); 
        v[i] = 1; 
        return c[i];
    }
}
int main(){
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        vector<long long> c(n+1), v(n+1, 0);
        for(int i = 1; i <= n; i++){
            cin >> c[i]; 
        }
        vector<vector<int>> mix(n+1); 
        for(int i = 0; i < k; i++){
            int p; cin >> p; 
            c[p] = 0;
            v[p] = 1; 
        }
        for(int i = 1; i <= n; i++){
            int m; cin >> m; 
            for(int j = 1; j <= m; j++){
                int p; cin >> p;
                mix[i].push_back(p);
            }
            if(m == 0){
                v[i] = 1; 
            }
        }

        for(int i = 1; i <= n; i++){
            if(i-1) cout << " "; 
            cout << calc(i, mix, c, v);
        }
        cout << "\n";
    }
    return 0; 
}