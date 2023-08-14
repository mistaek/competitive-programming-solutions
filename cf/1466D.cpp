/*
1466D
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        long long ans = 0;
        vector<int> w(n), e(n, 0); 
        for(int i = 0; i < n; i++){
            cin >> w[i]; 
            ans += w[i];
        }
        priority_queue<int> take; 
        for(int i = 0; i < n -1; i++){
            int u, v; cin >> u >> v;
            e[u-1]++; e[v-1]++;
            if(e[u-1] > 1) take.push(w[u-1]); 
            if(e[v-1] > 1) take.push(w[v-1]);
        }
        
        
        for(int i = 0; i < n-1; i++){
            cout << ((i) ? " " : "") << ans;
            if(!take.empty()){
                ans += take.top(); 
                take.pop();
            }
        }
        cout <<"\n";


    }

    return 0;
}