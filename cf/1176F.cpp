/*
1176F
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std; 

int main(){
    int n; cin >> n; 
  
    vector<vector<long long>> dp(2, vector<long long>(10, -1e18));
    dp[0][0] = 0;
    for(int i = 0; i < n; ++i){
        vector<vector<long long>> topdmg(3); 
        long long best3 = 0; 
        long long best2 = 0;
        long long best11 = 0, best12 = 0, best13 = 0; 

        long long k; cin >> k; 
        for(int j = 0; j < k; ++j){
            long long c, d; 
            cin >> c >> d; 
            if(c == 3) best3 = max(best3, d); 
            else if(c == 2) best2 = max(best2, d); 
            else if(c == 1){
                if(d >= best11) {
                    best13 = best12; 
                    best12 = best11;
                    best11 = d; 
                }
                else if (d >= best12) {
                    best13 = best12; 
                    best12 = d; 
                }
                else if (d >=best13){
                    best13 = d; 
                }
            }
        }
        // play j+1 cards
        topdmg[0].push_back(max(best11, max(best2, best3)));
        long long scnd = max(best2, best12); 
        topdmg[1].push_back(min(best11, scnd));
        topdmg[1].push_back(max(best11, scnd));
        topdmg[2] = {best13, best12, best11}; 
        for(int j = 0; j < 10; ++j){
            // play nothing
            dp[1][j] = max(dp[1][j], dp[0][j]);
            // play 1 card (always possible)
            dp[1][(j+1)%10] = max(dp[1][(j+1)%10], dp[0][j] + ((j == 9) ? 2 : 1) * topdmg[0][0]);
            //play 2 cards
            if (topdmg[1][0] != 0) {
                dp[1][(j+2)%10] = max(dp[1][(j+2)%10], dp[0][j] + topdmg[1][0] + ((j >= 8) ? 2 : 1) * topdmg[1][1]);
            }
            // play 3 cards
            if(topdmg[2][0] != 0) {
                dp[1][(j+3) % 10] = max(dp[1][(j+3)%10], dp[0][j] + topdmg[2][0] + topdmg[2][1] + ((j >=7) ? 2 : 1) * topdmg[2][2]); 
            }
        }
        dp[0] = std::move(dp[1]);
        dp[1] = vector<long long>(10, -1e9); 
    }

    long long ans = 0; 
    for(int i = 0; i < 10; ++i){
        ans = max(dp[0][i], ans); 
    }
    cout << ans << "\n";
    return 0;
}