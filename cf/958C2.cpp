/*
958C2
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<vector<long long>> dp; 
vector<long long> a;

int n, k, p; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> p; 
    dp = vector<vector<long long>>(k+1, vector<long long>(p, -1));
    a = vector<long long>(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
    }

    dp[0][a[0] % p] = 0;
    dp[1][0] = a[0] %p;
    for(int i = 1; i  <n; ++i){
        vector<vector<long long>> ndp(k+1, vector<long long>(p, -1)); 
        for(int j = 0; j <= k; ++j){
            long long mx = -1;
            for(int l = 0; l < p; ++l){
                if(dp[j][l] != -1){
                    ndp[j][(l + a[i]) % p] = max(ndp[j][(l + a[i]) % p], dp[j][l]);
                    mx = max(mx, dp[j][l] + ((l + a[i]) % p));
                }
            }
            if(j < k){
                ndp[j+1][0] = max(ndp[j+1][0], mx);
            }
        }
        /*
        long long mx = 0; 
        for(int j = 0; j <= k; ++j){
            for(int l = 0; l < p; ++l) {
                cout << ndp[j][l] << " "; 
            }
            cout << "\n"; 
        }
        for(int j = 0; j <= k; ++j) mx = max(mx, ndp[j][0]);
        cout << "End on " << i << " " << mx << "\n";
        */
        dp = std::move(ndp);
    }

    cout << dp[k][0] << "\n";


    return 0;
}