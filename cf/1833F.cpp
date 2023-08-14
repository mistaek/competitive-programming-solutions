/*
1833F
ac
*/


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std; 

long long MOD = 1e9+7;

long long getInv(long long a){
    //go to 1e9 + 5;
    long long ans = 1;  
    for(int i = 0; i < 32; i++){
        if((MOD - 2) & (1 << i)){
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
    }
    return (ans % MOD); 
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) {
        int n, m; cin >> n >>m; 
        vector<pair<long long, long long>> stu; 
        map<int, int> occ;
        
        for(int i = 0; i < n; i++){
            int a; 
            cin >> a; 
            if(occ[a] == 0){
                occ[a] = 1; 
                stu.push_back({a, 1});
            }
            else occ[a]++;
        }
        sort(stu.begin(), stu.end());
        long long prod[stu.size()];
        for(int i = 0; i < stu.size();i++){
            
            stu[i].second = occ[stu[i].first];
            prod[i] = stu[i].second;
            if(i){
                prod[i] *= prod[i-1];
                prod[i] %= MOD;
            }
            if(i >= m){
                long long inv = getInv(stu[i-m].second);
                prod[i] *= inv; 
                prod[i] %= MOD;
            }
        }
        long long ans = 0;
        long long j = stu.size(); 
        j += 1-m;
        for(int i = 0; i< j; i++){
            if((stu[i + m - 1].first - stu[i].first) < m){
                ans += prod[i+m-1];
                ans %= MOD;
            }
        }//*/
        /*
        for(int i = 0; i < stu.size(); i++){
            cout << stu[i].first << " " << stu[i].second << " " << prod[i] << "\n";
        }
        */
       
        cout << ans << "\n";
    }
    
    return 0;
}