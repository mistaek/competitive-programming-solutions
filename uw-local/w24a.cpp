/*
w24 a
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std; 

long long dp[131073][21] = {};
int important[15] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20};
int unimportant[5] = {1, 11, 13, 17, 19};
long long ans = 0;
int cnt[21] = {}; 

int gcd(int a, int b){
    if(b == 0) return a; 
    return gcd(b, a % b);
}

long long backtrack(int state, int last){
    if(dp[state][last] != 0) return dp[state][last]; 
    if(state == 0) return 0;
    for(int i = 0; i < 15; i++){
        if(state & (1 << i)){
            int nxt = important[i]; 
            long long nval = 0;
            if(last != 0) nval += gcd(nxt, last);
            nval += (cnt[nxt] - 1)*nxt + backtrack(state - (1 << i), nxt);
            dp[state][last] = max(dp[state][last], nval);
        }
    }
    return dp[state][last];
}


int main(){
    int n; cin >> n; 
    int a[n];
    int start = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i]; 
        cnt[a[i]]++; 
    }
    for(int i = 0; i < 15; i++){
        if(cnt[important[i]]) start |= (1 << i); 
    }

    int prev = 0; 
    for(int i = 0; i < 5; i++){
        if(cnt[unimportant[i]]){
            if(prev) ans++;
            ans += (cnt[unimportant[i]] - 1) * unimportant[i];
            prev = unimportant[i];
        }
    }
    
    cnt[1] = cnt[11] = cnt[13] = cnt[17]=  cnt[19] = 0;
    
    cout <<  ans + backtrack(start, prev) << "\n";
    
    
    return 0;
}
