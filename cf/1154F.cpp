    /*
    1154F
    */
     
    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <functional>
     
    using namespace std; 
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0); 
        int n, m, k; cin >> n >> m >> k;
        vector<int> dp(k+1, 1e9); 
        vector<int> deals(k+1, 0);
        vector<int> shovels(n);
        vector<int> psa(k, 0); // up to 4 * 10^8 
        for(int i = 0; i < n; ++i){
            cin >> shovels[i]; 
        }
        sort(shovels.begin(), shovels.end()); 
        for(int i = 0; i < k; ++i){
            if(i) psa[i] += psa[i-1]; 
            psa[i] += shovels[i]; 
        }
     
        for(int i = 0; i < m; ++i){
            int x, y; cin >> x >> y; 
            if(x > k) continue; 
            deals[x] = max(deals[x], y); 
        }
        for(int i = 1; i <= k; ++i) if(i) dp[i] = psa[i-1]; 
        dp[0] = 0;
        for(int i = 1; i <= k; ++i) for(int j = 1; j <= i; ++j) dp[i] = min(dp[i], dp[i-j] + psa[i-1] - ((i - j - 1 + deals[j] >= 0) ? psa[i-j-1+deals[j]] : 0)); 
        cout << dp[k]<< "\n"; 
        return 0;
    }