    /*
    1152D
    */
     
    #include <iostream>
    #include <algorithm>
    #include <vector>
     
    using namespace std; 
    using ll = long long;
    using pll = pair<long long,long long>; 
     
    ll mod = 1e9+7; 
    vector<vector<pll>> dp;
     
    bool operator==(const pll& a, const pll& b){
        return a.first == b.first && a.second == b.second;
    }
    bool operator!= (const pll& a, const pll& b){
        return !(a == b); 
    }
     
    pll solve(int i, int j){
        if(dp[i][j] != make_pair(-1LL, -1LL)) return dp[i][j]; 
        if(j == 0 && i != 0){
            cout << "wot\n";
            return {0, 0};
        }
     
        if(i == j){ // only can close
            pll a = solve(i-1, j-1); 
            dp[i][j] = {a.second + 1, a.first}; //even, odd
            dp[i][j].first %= mod; 
            dp[i][j].second %= mod; 
            return dp[i][j]; 
        }
     
        if(i == 0){
            // only open, root node
            pll a = solve(i+1, j); 
     
            dp[i][j] = {a.second + 1, a.first}; 
            dp[i][j].first %= mod; 
            dp[i][j].second %= mod; 
            return dp[i][j]; 
        }
     
        pll& ans = dp[i][j]; 
        //open 1
        
        pll a = solve(i+1, j); 
        ans = {a.second + 1, a.first};
     
        // close 1
        a = solve(i-1, j-1); //includes the close i think?
        ans.first += a.second; 
        ans.second += a.first; 
        ans.first %= mod; 
        ans.second %= mod; 
        return ans; 
    }
    int main(){
        int n; cin >> n; 
        dp = vector<vector<pll>>(n+1, vector<pll>(n+1, {-1, -1}));
     
        //base cases
        dp[0][0] = {1, 0};
     
        pll ans = solve(0, n);
        
        cout << ans.second << "\n"; //always take second? don't have proof for this
        
        /*
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= n; ++j){
                if(dp[i][j] == make_pair(-1LL, -1LL)) continue; 
                cout << i << " " << j << " " << dp[i][j].first << " " << dp[i][j].second << "\n"; 
            }
        }*/
     
        return 0;
    }