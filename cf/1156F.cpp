/*
1156F
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

const int MOD = 998244353;

int mul(int a, int b) { return 1LL*a *b%MOD;}
int add(int a, int b) { return (a + b) % MOD;}
int binexp(int a, int e){
    int ans = 1; 
    int pow = a; 
    for(int i = 0; i < 30; ++i){
        if((1LL << i) & e) ans = mul(ans, pow); 
        pow = mul(pow, pow); 
    }
    return ans; 
}

int inv(int a){ return binexp(a, MOD-2); }

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    
    int n; cin >> n; 
    vector<int> a(n); 
    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
    }
    sort(a.begin(), a.end(), greater<int>()); 
    
    int ctr = 0;
    vector<int> cnt(n, 0); 
    cnt[0] = 1; 
    for(int i = 1; i < n; ++i){
        if(a[i] != a[i-1]){
            ++ctr; 
        }
        cnt[ctr]++; 
    }


    vector<vector<int>> dp(ctr+1, vector<int>(ctr+2, 0)), psa(ctr+1, vector<int>(ctr+2, 0)); 
    //dp[i][j] is probability of winning if the last selected card was i and we have selected a total of j cards.
    // all j cards must have been >= i


    for(int i = 0; i <= ctr; ++i){
        for(int j = 1; j <= ctr+1 - i; ++j){
            // must have selected at least 1 card
            // can select at most ctr+1 - i cards, since there are ctr+1 total types of cards, and i cards > this card. 

            int invrem = inv(n - j); // number of remaining cards 
            
            dp[i][j] = mul(invrem, add(cnt[i]-1, (i ? psa[i-1][j+1] : 0)));
            psa[i][j] = mul(cnt[i], dp[i][j]); 
            if(i) psa[i][j] = add(psa[i][j], psa[i-1][j]);
            //cout << i << " " << j << " " << dp[i][j] << "\n"; 
        }
    }
    /*cout << inv(2) << " " << inv(3) << " " << inv(6) << "\n"; 
    cout << psa[1][2] << "\n";*/
    int ans = 0; 
    for(int i = 0; i <= ctr; ++i){
        ans = add(ans, mul(inv(n), mul(cnt[i], dp[i][1])));
    }

    cout << ans << "\n";
    return 0;
}