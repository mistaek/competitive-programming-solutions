/*
1015F
AC, multiple bugs with z algo
*/
 
#include <iostream>
#include <string>
 
using namespace std; 
 
long long MOD = 1e9+7;
int main(){
    int n; cin >> n; 
    string s; cin >> s; 
 
    int m = s.length(); 
 
    int trans[m+1][2]; 
    trans[m][0] = trans[m][1] = m; //don't transition out of this state
 
    //prefix function
    int pi[m] = {};
    for(int i = 1; i < m; ++i){
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
 
    for(int i = 0; i <m; ++i){
        if(s[i] == '('){
            trans[i][0] = i+1;
            trans[i][1] = (s[0] == ')');
            if(i){
                trans[i][1] = trans[pi[i-1]][1];
            }
        }
        if(s[i] == ')'){
            trans[i][1] = i+1;
            trans[i][0] = (s[0] == '(');
            if(i){
                trans[i][0] = trans[pi[i-1]][0];
            }
        }
        //cout << i << " " << trans[i][0] << " " << trans[i][1] << "\n";
    }
 
    long long dp[2*n+1][n+1][m+1] = {}; // length, current number of (, matched characters
    if(s[0] == '(') dp[1][1][1] = 1; 
    else dp[1][1][0] = 1;
    for(int i = 2; i <= 2*n; ++i){
        for(int j = 0; j <= n; ++j){
            for(int k = 0; k <= m; ++k){
                if(j < n){
                    dp[i][j+1][trans[k][0]] += dp[i-1][j][k];
                    dp[i][j+1][trans[k][0]] %= MOD; 
                    //can add another (
                }
                if(j){
                    dp[i][j-1][trans[k][1]] += dp[i-1][j][k]; 
                    dp[i][j-1][trans[k][1]] %= MOD;
                }
            
            }
        }
    }
    cout << dp[2*n][0][m] << "\n";
    return 0;
}