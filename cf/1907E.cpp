/*
1907E
ac
*/

#include <iostream>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);

    int dp[10][3] = {};

    for(int i = 0; i < 10; i++){
        dp[i][0] = 1;
        for(int j = 0; j <= i; j++){
            dp[i][1] ++;
        }
        for(int j = 0; j <= i; j++){
            dp[i][2]+= dp[j][1];
        }
    }

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        long long ans = 1;
        while(n){
            ans *= dp[n%10][2]; 
            n/=10;
        }
        cout << ans<< "\n";
    }
    return 0;
}