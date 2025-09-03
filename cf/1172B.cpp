    /*
    1172B
    */
     
    #include <iostream>
    #include <vector>
     
    using namespace std; 
     
    const long long MOD = 998244353;
    int main(){
        ios_base::sync_with_stdio(false); 
        cin.tie(0); 
     
        int n; cin >> n; 
        vector<int> cnt(n+1, 0); 
        long long ans = 1; 
        for(int i = 0; i < n-1; ++i){
            int u, v; cin >> u >> v; 
            ++cnt[u]; ++cnt[v]; 
        }
        vector<long long> fac(n+1, 0);
        fac[0] = 1; 
        for(int i = 1; i < n; ++i){
            fac[i] = i * fac[i-1] % MOD; 
        }
        ans = n; 
        for(int i = 1; i <= n; ++i){
            ans = ans * fac[cnt[i]] % MOD; 
        }   
        cout << ans << "\n"; 
        return 0;
    }