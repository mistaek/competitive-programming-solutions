/*
1155D
*/
 
#include <iostream>
#include <vector>
#include <algorithm> 
 
using namespace std; 
 
long long dp[300001][3] = {}; //best prefix of [i...n]
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    int n, x; cin >> n >> x; 
    vector<long long> a(n); 
    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
    }
 
    
    long long ans = 0; 
    
    for(int i = n-1; i >=0; --i){
        dp[i][0] = max(0ll, max(a[i] + dp[i+1][0], a[i] + dp[i+1][1]));
        dp[i][1] = max(0ll, max(a[i]*x + dp[i+1][1], a[i]*x + dp[i+1][2]));
        dp[i][2] = max(0ll, a[i] + dp[i+1][2]);
        ans = max(ans, max(dp[i][0], dp[i][1])); 
    }
 
    cout << ans << "\n"; 
    return 0;
}