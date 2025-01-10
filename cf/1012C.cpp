/*
1012C
AC
*/

#include <iostream>
#include <algorithm>

using namespace std; 

long long dp[5002][2501][2] = {};

int main(){
    int n; cin >> n; 
    int a[n]; 
    

    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
    }
    
    

    //reaching n with any unused is fail
    for(int i = 1; i <= (n+1)/2; ++i) dp[n][i][0] = dp[n][i][1] = dp[n+1][i][0] = dp[n+1][i][1] = 1e10;
    
    for(int i = n-1; i >= 0; --i){
        for(int j = 1; j <= (n+1)/2; ++j){
            //1 CASE: i-2 was selected
            long long cost = 0;
            if(i < n-1) cost += max(0, a[i+1] - a[i] + 1); //cost to reduce i+1 to a[i] - 1
            if(i>=2){
                //1 means that we've shaved some off i-1 already: 
                // a[i-1] is a[i-2] - 1 OR a[i-1], whichever is smaller
                cost += max(0, min(a[i-2]-1, a[i-1]) -a[i] +1);
            }
            dp[i][j][1] = min(dp[i+1][j][0], cost + dp[i+2][j-1][1]);
           
            //0 CASE: i-2 was not selected. 
            cost = 0;
            if(i < n-1) cost += max(0, a[i+1] - a[i] + 1); // same as b4
            if(i){
                cost += max(0, a[i-1] - a[i] + 1); // i-1 is untouched
            }
            dp[i][j][0] = min(dp[i+1][j][0], cost + dp[i+2][j-1][1]);
        }
    }
    
    for(int i = 1; i <= (n+1)/2; ++i){
        if(i > 1) cout << " "; 
        cout << dp[0][i][0]; 
    }
    cout << "\n";
    //*/
    return 0; 
}