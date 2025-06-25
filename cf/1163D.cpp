/*
1163D
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

int dp[1002][52][52] = {}; 
int main(){
    string c; cin >> c; 
    string s, t; cin >> s >> t; 
    int clen = (int) c.length(), slen = (int) s.length(), tlen = (int) t.length(); 
    int spfn[52] = {}, tpfn[52] = {}; //prefix functions of s and t
    int cur = 0;
    for(int i = 1; i < slen; ++i){
        while(cur != 0){
            if(s[i] == s[cur]) break; 
            else cur = spfn[cur - 1];
        }
        if(s[i] == s[cur]) ++cur; 
        spfn[i] = cur; 
    }
    cur = 0;
    for(int i = 1; i < tlen; ++i){
        while(cur != 0){
            if(t[i] == t[cur]) break; 
            else cur = tpfn[cur - 1];
        }
        if(t[i] == t[cur]) ++cur; 
        tpfn[i] = cur; 
    }

    for(int i = 0; i <= clen; ++i){
        for(int j = 0; j < slen; ++j){
            for(int k = 0; k < tlen; ++k){
                dp[i][j][k] = -1e9; // unreachable states
            }
        }
    }
    int nj[52][26] = {};//precompute transitions for j
    int nk[52][26] = {};//precompute transitions for k

    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < slen; ++j){
            cur = j; 
            while(cur != 0){
                if((char)('a' + i) == s[cur]) break; 
                else cur = spfn[cur-1];
            }
            if((char)('a'+ i) == s[cur]) ++cur; 
            nj[j][i] = cur; 
        }
        for(int j = 0; j < tlen; ++j){
            cur = j; 
            while(cur != 0){
                if((char)('a' + i) == t[cur]) break; 
                else cur = tpfn[cur-1]; 
            }
            if((char)('a' + i) == t[cur]) ++cur; 
            nk[j][i] = cur; 
        }
    }
    dp[0][0][0] = 0; // reachable
    for(int i = 0; i < clen; ++i){
        for(int j = 0; j < slen; ++j){
            for(int k = 0; k < tlen; ++k){
                if(dp[i][j][k] == -1e9) continue; //unreachable state
                // we are considering index i, having matched j characters of s and k of t
                for(char ch = 'a'; ch <= 'z'; ++ch){
                    if(c[i] == '*' || c[i] == ch){
                        int nxtj = nj[j][ch-'a'], nxtk = nk[k][ch -'a'], scoreAdj = 0;
                        if(nxtj == slen){
                            ++scoreAdj; 
                            nxtj=spfn[nxtj-1];
                        }
                        if(nxtk == tlen){
                            --scoreAdj; 
                            nxtk = tpfn[nxtk-1];
                        }
                        dp[i+1][nxtj][nxtk] = max(dp[i][j][k] + scoreAdj, dp[i+1][nxtj][nxtk]); 
                    }
                }
            }
        }
    }
    int ans = -1e9;
    for(int j = 0; j < slen; ++j){
        for(int k = 0; k < tlen; ++k){
            ans = max(ans, dp[clen][j][k]); 
        }
    }
    cout << ans << "\n";
    return 0;
}