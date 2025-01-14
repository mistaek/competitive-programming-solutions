/*
1017D
AC, fast enough! 
*/

#include <iostream>
#include <string>

using namespace std; 

int cnt[4096] = {}; 
int psa[4096][101] = {};
int w[12] = {}; 
int n, q, m; 
int wu(int a, int b){
    int ans = 0; 
    for(int i = 0; i < n; ++i){
        if((a & (1 << i)) == (b&(1 << i))) ans += w[i]; 
    }
    return ans; 
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cin >> n >> m >> q ; 
    for(int i = 0; i < n; ++i){
        cin >> w[i]; 
    }
    
    for(int i = 0; i < m; ++i){
        string s; cin >> s;
        int cur = 0; 
        for(int i = 0; i < n; ++i){
            if(s[i] == '1') cur |= (1 << i); 
        }
        cnt[cur]++; 
    }

    for(int i = 0; i < (1 << n); ++i){
        for(int j = 0; j < (1 <<n); ++j){
            if(cnt[j] == 0) continue; 
            int wuwu = wu(i, j); 
            if(wuwu <=100) psa[i][wuwu] += cnt[j]; 
        }
        for(int j = 1; j <= 100; ++j){
            psa[i][j] += psa[i][j-1]; 
        }
    }

    for(int i = 0; i < q; ++i){
        int k; 
        int cur = 0; 
        string s; cin >> s >> k;  
        for(int i = 0; i < n; ++i){
            if(s[i] == '1') cur |= (1 << i); 
        }

        cout << psa[cur][k] << "\n";
    }

    return 0;   
}